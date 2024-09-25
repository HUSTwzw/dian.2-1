#define _CRT_SECURE_NO_WARNINGS 1
#define x 100
#include<stdio.h>
#include<string.h>
int main(void)
{
	char str[x] = "0";
	char grand[x];
	int number[x];
	int price[x];
	int amount[x] = { 0,0,0,0,0,0,0,0 };
	int amo_unt[x][2];
	int i = 0;



	char str2[x] = "0";
	char grand2[x];
	int number2[x];
	int amount2[x];
	int j = 1;
	int k = 0;
	int price2[x];
	int p = 1;
	int amo_unt2[x][2];
	int sum_price = 0;
	int r = 1;
	int t = 1;





	int sum_pay = 0;
	int once_pay = 0;
	int back = 0;



	char str3[x] = "0";




	for (; back >= 0;)
	{
		printf("温馨提示：在输入品牌、序号（1-5）（必须为个位数）、价格（1-9）（必须为个位数）、数量时请用一个空格隔开（输入数量后只需要回车）,每次输入通道序号不能相同(相同会判定为输入错误)，若完成全部输入可通过输入END结束当前环节\n");//局限性在于必须在输入不同数据时用一个空格隔开（只要不是一个空格此代码就不能正常运行，需要修改代码）
		rewind(stdin);
		for (i = 1; strcmp(str, "END") != 0;)//为了使第一次输入也能判断数量是否过多，必须设置为i=1
		{
			scanf("%c", &grand[i]);
			scanf("%d", &number[i]);
			scanf("%d", &price[i]);
			scanf("%d", &amount[i]);

			rewind(stdin);//彻底清空缓冲区

			if (amount[i] > 50)
			{
				printf("放入数量过多，此次投放无效\n");
				rewind(stdin);

				if (number[i] > 5 || number[i] < 1)
				{
					printf("通道序号输入错误，此次操作无效\n");
					rewind(stdin);
					if (price[i] > 9 || price[i] < 1)
					{
						printf("输入货物单价错误，此次操作无效\n");
						rewind(stdin);
					}
				}
				else if (price[i] > 9 || price[i] < 1)
				{
					printf("输入货物单价错误，此次操作无效\n");
					rewind(stdin);
				}
				i = i - 1;

			}
			else if (number[i] > 5 || number[i] < 1)
			{
				printf("通道序号输入错误，此次操作无效\n");
				rewind(stdin);

				if (price[i] > 9 || price[i] < 1)
				{
					printf("输入货物单价错误，此次操作无效\n");
					rewind(stdin);
				}
				i = i - 1;
			}
			else if (price[i] > 9 || price[i] < 1)
			{
				printf("输入货物单价错误，此次操作无效\n");
				rewind(stdin);
				i = i - 1;
			}
			else
			{
			}


			gets(str);
			for (; strcmp(str, "END") != 0;)
			{

				i++;

				if (i >= 6)//i=1为开始，因此必须以6为边界
				{
					printf("没有多余通道了,最近一次的输入无效\n");
					rewind(stdin);
					break;
				}
				else
				{
					grand[i] = str[0];
					number[i] = str[2] - 48;
					price[i] = str[4] - 48;
					amo_unt[i][0] = str[6];//输入的是数字字符对应的ASCII码值
					amo_unt[i][1] = str[7];
					if (amo_unt[i][1] == 0)
					{
						amount[i] = amo_unt[i][0] - 48;
					}
					else
					{
						amount[i] = (amo_unt[i][0] - 48) * 10 + amo_unt[i][1] - 48;
					}
					
					for (r = 1; grand[i] != grand[r] && r < i;)
					{
						r++;
					}
					for (t = 1; number[i] != number[t] && i > t;)
					{
						t++;
					}


					if (amount[i] > 50||(str[8]>=48&&str[8]<=57))
					{
						printf("放入数量过多，此次投放无效\n");
						rewind(stdin);
						

						if (number[i] > 5 || number[i] < 1 || str[3] != 32||t<i)
						{
							printf("通道序号输入错误，此次操作无效\n");
							rewind(stdin);
							if (str[5] != 32 || price[i] < 1)
							{
								printf("输入货物单价错误，此次操作无效\n");
								rewind(stdin);
							}
							if (grand[i] == grand[r] && price[i] != price[r])
							{
								printf("同种货物价格不统一，此次操作无效\n");
								rewind(stdin);
							}
							
						}
						else if (str[5] != 32 || price[i] < 1)
						{
							printf("输入货物单价错误，此次操作无效\n");
							rewind(stdin);
							if (grand[i] == grand[r] && price[i] != price[r])
							{
								printf("同种货物的单价不统一，此次操作无效\n");
								rewind(stdin);
							}

						}
						else if (grand[i] == grand[r] && price[i] != price[r])
						{
							printf("同种货物的单价不统一，此次操作无效\n");
							rewind(stdin);
							
						}
						
						memset(str, 0, sizeof(str));
						number[i] = 0;
						amount[i] = 0;
						i = i - 1;
						gets(str);
					}
					else if (number[i] > 5 || number[i] < 1 || str[3] != 32||t<i)
					{
						printf("通道序号输入错误，此次操作无效\n");
						rewind(stdin);


						if (str[5] != 32 || price[i] < 1)
						{
							printf("输入货物单价错误，此次操作无效\n");
							rewind(stdin);
							if (grand[i] == grand[r] && price[i] != price[r])
							{
								printf("同种货物的单价不统一，此次操作无效\n");
								rewind(stdin);
							}

						}
						else if (grand[i] == grand[r] && price[i] != price[r])
						{
							printf("同种货物的单价不统一，此次操作无效\n");
							rewind(stdin);

						}
						number[i] = 0;
						amount[i] = 0;
						i = i - 1;
						gets(str);
					}
					else if (str[5] != 32 || price[i] < 1)
					{
						printf("输入货物单价错误，此次操作无效\n");
						rewind(stdin);
						if (grand[i] == grand[r] && price[i] != price[r])
						{
							printf("同种货物的单价不统一，此次操作无效\n");
							rewind(stdin);

						}
						amount[i] = 0;
						i = i - 1;
						gets(str);
					}
					else if (grand[i] == grand[r] && price[i] != price[r])
					{
						printf("同种货物的单价不统一，此次操作无效\n");
						rewind(stdin);
						amount[i] = 0;
						i = i - 1;
						gets(str);
					}

					else
					{
						gets(str);
					}
				}

			}
			break;
		}
		memset(str, 0, sizeof(str));
		printf("结束放货环节\n");





		j = 1;
		p = 1;
		printf("开始取货环节\n");
		rewind(stdin);
		scanf("%c", &grand2[j]);
		scanf("%d", &number2[j]);
		scanf("%d", &amount2[j]);
		rewind(stdin);

		for (k = 1; (grand2[j] != grand[k] || number2[j] != number[k]) && k < 6;)
		{
			k++;
		}
		if (k == 6)
		{
			printf("输入的商品种类与通道号不对应，商品种类和通道号至少有一个错误，此次输入无效\n");
			rewind(stdin);
			j = j - 1;
		}
		else if (amount2[j] > amount[k])
		{
			printf("所要购买的货物数量不足，此次操作无效\n");
			rewind(stdin);
			j = j - 1;
		}
		else
		{
			price2[p] = amount2[j] * price[k];
			sum_price += price2[p];
			amount[k] -= amount2[j];
		}
		gets(str2);

		for (; (amount[1] > 0 || amount[2] > 0 || amount[3] > 0 || amount[4] > 0 || amount[5] > 0);)
		{
			for (; strcmp(str2, "END") != 0;)
			{
				j++;
				grand2[j] = str2[0];
				number2[j] = str2[2] - 48;
				amo_unt2[j][0] = str2[4];
				amo_unt2[j][1] = str2[5];
				if (amo_unt2[j][1] == 0)
				{
					amount2[j] = amo_unt2[j][0] - 48;
				}
				else
				{
					amount2[j] = (amo_unt2[j][0] - 48) * 10 + amo_unt2[j][1] - 48;
				}

				for (k = 1; (grand2[j] != grand[k] || number2[j] != number[k]) && k < 6;)
				{
					k++;
				}
				if (k == 6)
				{
					printf("输入的商品种类与通道号不对应，商品种类和通道号至少有一个错误，此次输入无效\n");
					rewind(stdin);
					if (str2[6] >= 48 && str[6] <= 57)
					{
						printf("所要购买的货物数量不足，此次操作无效\n");
						rewind(stdin);
						memset(str2, 0, sizeof(str2));
					}
					amount2[j] = 0;
					j = j - 1;
				}
				else if (amount2[j] > amount[k]||(str2[6]>=48&&str[6]<=57))
				{
					printf("所要购买的货物数量不足，此次操作无效\n");
					rewind(stdin);
					memset(str2, 0, sizeof(str2));
					amount2[j] = 0;
					j = j - 1;
					
				}
				else
				{
					p++;
					price2[p] = amount2[j] * price[k];
					sum_price += price2[p];
					amount[k] -= amount2[j];

				}
				gets(str2);
			}
			memset(str2, 0, sizeof(str2));



			printf("开始收钱，请投入1元、2元或5元\n");
			for (sum_pay = 0; sum_pay < sum_price;)
			{
				printf("请投入钱\n");
				scanf("%d", &once_pay);
				if (once_pay != 1 && once_pay != 2 && once_pay != 5)
				{
					printf("投入金额错误，此次投入无效\n");
				}
				else
				{
					sum_pay += once_pay;
				}
			}
			back = sum_pay - sum_price;
			printf("找零%d\n", back);
			if (amount[1] > 0 || amount[2] > 0 || amount[3] > 0 || amount[4] > 0 || amount[5] > 0)
			{
				printf("找零完毕，售货机内剩余0元，售货机内还剩余部分货物，可以继续购买，也可输入END结束全流程\n");
				back = 0;
				sum_price = 0;
				rewind(stdin);
				gets(str3);
			}
			else
			{
				printf("售货机内已不存在任何商品，此轮完整流程流程将结束\n");
				rewind(stdin);
				break;
			}
			if (strcmp(str3, "END") == 0)
			{
				break;
			}
			else
			{
				strcpy(str2, str3);
			}
		}
		memset(str2, 0, sizeof(str2));
		if (amount[1] > 0 || amount[2] > 0 || amount[3] > 0 || amount[4] > 0 || amount[5] > 0)
		{
			printf("本次完整流程已结束，售货机内剩余商品将自动清除，若要再次购买可以重新摆放货物\n");
		}
		else
		{
			printf("本次完整流程已结束,售货机内不剩余任何商品，若要再次购买可以重新摆放货物\n");
		}


	}

}