#include<locale.h>
#include<stdio.h>

int ust(int x, int y) {
	if(x>y)
	return x;
	if(x<y)
	return y;
 }

int yerlestir( int esyaSayisi,int cantaHacmi, int miktar[], int fiyat[])
{
    int s, h;
    int K[esyaSayisi+1][cantaHacmi+1];

    for (s = 0; s <= esyaSayisi; s++)
    {
        for (h = 0; h <= cantaHacmi; h++)
        {
            if (s==0 || h==0)
                K[s][h] = 0;
            else if (miktar[s-1] <= h)
                K[s][h] = ust(fiyat[s-1] + K[s-1][h-miktar[s-1]],  K[s-1][h]);
            else
                K[s][h] = K[s-1][h];
        }
    }

    return K[esyaSayisi][cantaHacmi];
}

int main()
{
	
	setlocale(LC_ALL, "Turkish"); 

    int index=0, esyaSayisi, fiyat[20], miktar[20], cantaHacmi;

    printf("Girilecek eþya sayýsý:");
    scanf("%d", &esyaSayisi);

    printf("Eþyalarýn fiyat ve niktarýný giriniz:\n");
    while(index < esyaSayisi){
        printf("%d.Eþyayý giriniz\n",index+1);
        scanf("%d%d", &fiyat[index], &miktar[index]);
        index++;
    }

    printf("Çanta Hacmini Giriniz:");
    scanf("%d", &cantaHacmi);

    printf("%d", yerlestir( esyaSayisi,cantaHacmi, miktar, fiyat));
    return 0;
}
