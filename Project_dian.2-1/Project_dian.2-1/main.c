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
		printf("��ܰ��ʾ��������Ʒ�ơ���ţ�1-5��������Ϊ��λ�������۸�1-9��������Ϊ��λ����������ʱ����һ���ո����������������ֻ��Ҫ�س���,ÿ������ͨ����Ų�����ͬ(��ͬ���ж�Ϊ�������)�������ȫ�������ͨ������END������ǰ����\n");//���������ڱ��������벻ͬ����ʱ��һ���ո������ֻҪ����һ���ո�˴���Ͳ����������У���Ҫ�޸Ĵ��룩
		rewind(stdin);
		for (i = 1; strcmp(str, "END") != 0;)//Ϊ��ʹ��һ������Ҳ���ж������Ƿ���࣬��������Ϊi=1
		{
			scanf("%c", &grand[i]);
			scanf("%d", &number[i]);
			scanf("%d", &price[i]);
			scanf("%d", &amount[i]);

			rewind(stdin);//������ջ�����

			if (amount[i] > 50)
			{
				printf("�����������࣬�˴�Ͷ����Ч\n");
				rewind(stdin);

				if (number[i] > 5 || number[i] < 1)
				{
					printf("ͨ�����������󣬴˴β�����Ч\n");
					rewind(stdin);
					if (price[i] > 9 || price[i] < 1)
					{
						printf("������ﵥ�۴��󣬴˴β�����Ч\n");
						rewind(stdin);
					}
				}
				else if (price[i] > 9 || price[i] < 1)
				{
					printf("������ﵥ�۴��󣬴˴β�����Ч\n");
					rewind(stdin);
				}
				i = i - 1;

			}
			else if (number[i] > 5 || number[i] < 1)
			{
				printf("ͨ�����������󣬴˴β�����Ч\n");
				rewind(stdin);

				if (price[i] > 9 || price[i] < 1)
				{
					printf("������ﵥ�۴��󣬴˴β�����Ч\n");
					rewind(stdin);
				}
				i = i - 1;
			}
			else if (price[i] > 9 || price[i] < 1)
			{
				printf("������ﵥ�۴��󣬴˴β�����Ч\n");
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

				if (i >= 6)//i=1Ϊ��ʼ����˱�����6Ϊ�߽�
				{
					printf("û�ж���ͨ����,���һ�ε�������Ч\n");
					rewind(stdin);
					break;
				}
				else
				{
					grand[i] = str[0];
					number[i] = str[2] - 48;
					price[i] = str[4] - 48;
					amo_unt[i][0] = str[6];//������������ַ���Ӧ��ASCII��ֵ
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
						printf("�����������࣬�˴�Ͷ����Ч\n");
						rewind(stdin);
						

						if (number[i] > 5 || number[i] < 1 || str[3] != 32||t<i)
						{
							printf("ͨ�����������󣬴˴β�����Ч\n");
							rewind(stdin);
							if (str[5] != 32 || price[i] < 1)
							{
								printf("������ﵥ�۴��󣬴˴β�����Ч\n");
								rewind(stdin);
							}
							if (grand[i] == grand[r] && price[i] != price[r])
							{
								printf("ͬ�ֻ���۸�ͳһ���˴β�����Ч\n");
								rewind(stdin);
							}
							
						}
						else if (str[5] != 32 || price[i] < 1)
						{
							printf("������ﵥ�۴��󣬴˴β�����Ч\n");
							rewind(stdin);
							if (grand[i] == grand[r] && price[i] != price[r])
							{
								printf("ͬ�ֻ���ĵ��۲�ͳһ���˴β�����Ч\n");
								rewind(stdin);
							}

						}
						else if (grand[i] == grand[r] && price[i] != price[r])
						{
							printf("ͬ�ֻ���ĵ��۲�ͳһ���˴β�����Ч\n");
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
						printf("ͨ�����������󣬴˴β�����Ч\n");
						rewind(stdin);


						if (str[5] != 32 || price[i] < 1)
						{
							printf("������ﵥ�۴��󣬴˴β�����Ч\n");
							rewind(stdin);
							if (grand[i] == grand[r] && price[i] != price[r])
							{
								printf("ͬ�ֻ���ĵ��۲�ͳһ���˴β�����Ч\n");
								rewind(stdin);
							}

						}
						else if (grand[i] == grand[r] && price[i] != price[r])
						{
							printf("ͬ�ֻ���ĵ��۲�ͳһ���˴β�����Ч\n");
							rewind(stdin);

						}
						number[i] = 0;
						amount[i] = 0;
						i = i - 1;
						gets(str);
					}
					else if (str[5] != 32 || price[i] < 1)
					{
						printf("������ﵥ�۴��󣬴˴β�����Ч\n");
						rewind(stdin);
						if (grand[i] == grand[r] && price[i] != price[r])
						{
							printf("ͬ�ֻ���ĵ��۲�ͳһ���˴β�����Ч\n");
							rewind(stdin);

						}
						amount[i] = 0;
						i = i - 1;
						gets(str);
					}
					else if (grand[i] == grand[r] && price[i] != price[r])
					{
						printf("ͬ�ֻ���ĵ��۲�ͳһ���˴β�����Ч\n");
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
		printf("�����Ż�����\n");





		j = 1;
		p = 1;
		printf("��ʼȡ������\n");
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
			printf("�������Ʒ������ͨ���Ų���Ӧ����Ʒ�����ͨ����������һ�����󣬴˴�������Ч\n");
			rewind(stdin);
			j = j - 1;
		}
		else if (amount2[j] > amount[k])
		{
			printf("��Ҫ����Ļ����������㣬�˴β�����Ч\n");
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
					printf("�������Ʒ������ͨ���Ų���Ӧ����Ʒ�����ͨ����������һ�����󣬴˴�������Ч\n");
					rewind(stdin);
					if (str2[6] >= 48 && str[6] <= 57)
					{
						printf("��Ҫ����Ļ����������㣬�˴β�����Ч\n");
						rewind(stdin);
						memset(str2, 0, sizeof(str2));
					}
					amount2[j] = 0;
					j = j - 1;
				}
				else if (amount2[j] > amount[k]||(str2[6]>=48&&str[6]<=57))
				{
					printf("��Ҫ����Ļ����������㣬�˴β�����Ч\n");
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



			printf("��ʼ��Ǯ����Ͷ��1Ԫ��2Ԫ��5Ԫ\n");
			for (sum_pay = 0; sum_pay < sum_price;)
			{
				printf("��Ͷ��Ǯ\n");
				scanf("%d", &once_pay);
				if (once_pay != 1 && once_pay != 2 && once_pay != 5)
				{
					printf("Ͷ������󣬴˴�Ͷ����Ч\n");
				}
				else
				{
					sum_pay += once_pay;
				}
			}
			back = sum_pay - sum_price;
			printf("����%d\n", back);
			if (amount[1] > 0 || amount[2] > 0 || amount[3] > 0 || amount[4] > 0 || amount[5] > 0)
			{
				printf("������ϣ��ۻ�����ʣ��0Ԫ���ۻ����ڻ�ʣ�ಿ�ֻ�����Լ�������Ҳ������END����ȫ����\n");
				back = 0;
				sum_price = 0;
				rewind(stdin);
				gets(str3);
			}
			else
			{
				printf("�ۻ������Ѳ������κ���Ʒ�����������������̽�����\n");
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
			printf("�������������ѽ������ۻ�����ʣ����Ʒ���Զ��������Ҫ�ٴι���������°ڷŻ���\n");
		}
		else
		{
			printf("�������������ѽ���,�ۻ����ڲ�ʣ���κ���Ʒ����Ҫ�ٴι���������°ڷŻ���\n");
		}


	}

}