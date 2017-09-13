#include <stdio.h>
void exibirLetraD(int vetorLetraD[])
{
	int i;
	for (i=0;i<10;i++)
	{
		if(vetorLetraD[i]==0)
			printf("NAO HOUVE VENDAS DO CANDIDATO %d\n",i+1);
		else
			printf("MERCADORIA COM O MAIOR QUANTIDADE VENDIDA DO VENDEDOR %d foi %d\n",i+1,i);
	
	}
}
void valorUnitarioMedio (float valorVendido[],int qntVendido [])
{
	int i;
	float valorUnitM[10];
	for(i=0;i<10;i++)
	{
		valorUnitM[i]=valorVendido[i]/qntVendido[i];
	}
	for(i=0;i<10;i++)
	{
		printf("Vendedor %d Valor Unitario Medio %.2f\n",i+1,valorUnitM[i]);
	}

}
void maiorVendedor (float vetorVendedor[], int vetorLetraB[])
{
	float maior;
	int i;
	maior=0;
	for(i=0;i<10;i++)
	{
		if(maior<vetorVendedor[i])
		{
			maior=vetorVendedor[i];		
			vetorLetraB[i]=i;		
		
		}
	}
	for(i=0;i<10;i++)
	{
		if(vetorLetraB[i]!=0)
			printf("\nO CODIGO DO MAIOR VENDEDOR E %d\n",(vetorLetraB[i]+1)*10);
	}

	return;
}
void quantidadeVendida (int vetorLetraC[], int vetorLetraC2[])
{
	int i;
	for(i=0;i<5;i++)
	{
		while(vetorLetraC[i]>100)
		{
			vetorLetraC2[i]+=1;
			vetorLetraC[i]-=100;
		}	
	}
	for(i=0;i<5;i++)
	{
			printf("\nA Quantidade Vendida da Mercadoria %d foi %d vez maior que 100\n",i+1,vetorLetraC2[i]);
	}
	return;
}
void zeraVetor1 (float v[])
{
	int i;
	for(i=0;i<10;i++)
	{
		v[i]=0;
	}
	return;
}
void zeraVetor2 (int f[])
{
	int i;
	for(i=0;i<10;i++)
	{
		f[i]=0;
	}
	return;
}
void zeraVetor3 (int c[])
{
	int i;
	for(i=0;i<5;i++)
	{
		c[i]=0;
	}
	return;
}
void Mercadoria (float m[])
{
	int i;
	for(i=0;i<5;i++)
	{
		printf("Informe o preco da mercadoria %d\n",i+1);
		scanf_s("%f",&m[i]);
	}
	return;
}
int main (void)
{
	float mercadoria[5],vetorVendedor[10],valorUnitMedio[10];
	int m,j,vendedor,qntVendida,vetorQuantidadeVendida[10],vetorLetraB[10],vetorLetraC[5],vetorLetraC2[5],vetorLetraD[10];
	
	zeraVetor2(vetorLetraD);
	zeraVetor1(vetorVendedor);
	zeraVetor1(valorUnitMedio);
	zeraVetor2(vetorQuantidadeVendida);
	zeraVetor2(vetorLetraB);
	zeraVetor3(vetorLetraC);
	zeraVetor3(vetorLetraC2);
	Mercadoria(mercadoria);
	printf("Informe o COD do vendedor (10-100)\n");
	scanf_s("%d",&vendedor);	
	while(vendedor!=0)
	{
		printf("Informe o codigo da mercadoria\n");
		scanf_s("%d",&m);
		m-=1;
		printf("Qnt Vendida?\n");
		scanf_s("%d",&qntVendida);
		j=vendedor/10-1;
		vetorVendedor[j]+=qntVendida*mercadoria[m];
		vetorQuantidadeVendida[j]+=qntVendida;
		vetorLetraC[m]+=qntVendida;
		if(qntVendida>vetorLetraD[j])
			vetorLetraD[j]=m;
		printf("Informe o COD do vendedor (10-100)\n");
		scanf_s("%d",&vendedor);
	}
	printf("======================== RESPOSTAS ========================\n===========================================================\n===========================================================\n\n");
	valorUnitarioMedio(vetorVendedor,vetorQuantidadeVendida);
	printf("===========================================================\n\n");
	maiorVendedor(vetorVendedor, vetorLetraB);
	printf("===========================================================\n\n");
	quantidadeVendida (vetorLetraC,vetorLetraC2);
	printf("===========================================================\n\n");
	exibirLetraD(vetorLetraD);
	printf("===========================================================\n\n");
return 0;
}