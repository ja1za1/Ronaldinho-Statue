#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

void esferasOuNao (double *pesoEsferas,int *contEsferas,int i){
    switch(i){
        case 0:
            if(contEsferas[i] == 0)
                printf("\n\n9 - Não há nenhuma esfera de aço\n");
            else
                printf("\n\n9 - O peso médio das esferas de aço é de %.2lfG\n",(double)pesoEsferas[i]/contEsferas[i]);
        break;

        case 1:
            if(contEsferas[i] == 0)
                printf("\n\n9 - Não há nenhuma esfera de alumínio\n");
            else
                printf("\n\n9 - O peso médio das esferas de alumínio é de %.2lfG\n",(double)pesoEsferas[i]/contEsferas[i]);
        break;

        case 2:
            if(contEsferas[i] == 0)
                printf("\n\n9 - Não há nenhuma esfera de cobre\n");
            else
                printf("\n\n9 - O peso médio das esferas de cobre é de %.2lfG\n",(double)pesoEsferas[i]/contEsferas[i]);
        break;
    }



}

void pecasLojas (int *esferas,int *paralelepipedos,int *cilindros,int i){
    printf("4 - Foram %i esferas compradas nessa loja\n",esferas[i]);
    printf("4 - Foram %i paralelepípedos comprados nessa loja\n",paralelepipedos[i]);
    printf("4 - Foram %i cilindros comprados nessa loja\n",cilindros[i]);

    return;
}

float maiorPeso (float pesoPeca,float *maioresPesos,int materialPeca){
    switch(materialPeca){
        case 1:
            if(pesoPeca > maioresPesos[0])      // verificando o maior peso de cada tipo de material
                maioresPesos[0] = pesoPeca;

            return maioresPesos[0];
        break;

        case 2:
            if(pesoPeca > maioresPesos[1])
                maioresPesos[1] = pesoPeca;

            return maioresPesos[1];
        break;

        case 3:
            if(pesoPeca > maioresPesos[2])
                maioresPesos[2] = pesoPeca;

            return maioresPesos[2];
        break;
    }
    return 0;
}

int verificaDados (int a,int b){    //verifica se o dado entrado pelo usuário é um valor esperado
    int i;

    scanf("%i",&i);
    while(i < a || i > b){
        printf("Valor digitado inválido!!!\nPor favor digite um valor válido!!\n");
        scanf("%i",&i);
    }
    return(i);
}


int main(){
    const float PI = 3.14;
    int tipoPeca,materialPeca,latasTinta[3] = {0},lojaComprou,esferas[7] = {0},paralelepipedos[7] = {0},cilindros[7] = {0};
    int contEsferas[3] = {0};
    float medidasPara[3] ={0},raioEsfera=0,raioCil=0,altCil=0,consumoTinta,precoTotal=0,precoLoja[7] = {0},lojaMaisFaturou = 0;
    float maioresPesos[3] = {0},maioresVolumes[3] = {0},menoresVolumes[3] = {0};
    double volumePeca,areaPeca,pesoPeca,pesoTotal,maiorVolume=0,pesoEsferas[3] = {0},maiorVolumeCilindro = 0;
    setlocale(LC_ALL,"");

    do{
        printf("Digite 0 para sair do programa\n\n");
        printf("Qual é o tipo de peça comprada?\n1 - Esfera\n2 - Paralelepípedo\n3 - Cilindro\n0 - Sair do programa\n");
        tipoPeca = verificaDados(0,3);

        if (tipoPeca != 0){
            switch(tipoPeca){
                case 1:
                    printf("Digite o raio da esfera em MM\n");
                    scanf("%f",&raioEsfera);

                    volumePeca = ((float)4/3 * PI * raioEsfera * raioEsfera * raioEsfera)/1000; //dividindo volume por 1000 para armazenar o valor em cm³
                    areaPeca = (4 * PI * raioEsfera * raioEsfera)/100;  //dividindo a area por 100 para armazenar o valor em cm²
                break;

                case 2:
                    printf("Digite a altura do paralelepípedo em MM\n"); //indice 0 = altura
                    scanf("%f",&medidasPara[0]);
                    printf("Digite a largura do paralelepípedo em MM\n"); //indice 1 = largura
                    scanf("%f",&medidasPara[1]);
                    printf("Digite a profundidade do paralelepípedo em MM\n"); //indice 2 = profundidade
                    scanf("%f",&medidasPara[2]);

                    volumePeca = (medidasPara[0] * medidasPara[1] * medidasPara[2])/1000;
                    areaPeca = ((2 * medidasPara[0] * medidasPara[1]) + (2 * medidasPara[0] * medidasPara[2]) + (2 * medidasPara[1] * medidasPara[2]))/100;
                break;

                case 3:
                    printf("Digite o raio do cilindro em MM\n");
                    scanf("%f",&raioCil);
                    printf("Digite a altura do cilindro em MM\n");
                    scanf("%f",&altCil);

                    volumePeca = (PI * raioCil * raioCil * altCil)/1000;
                    areaPeca = ((2 * PI * raioCil * raioCil) + (2 * PI * raioCil * altCil))/100;

                    if(volumePeca > maiorVolumeCilindro){   //verificando se o volume do cilindro é o maior volume entre os cilindros
                        maiorVolumeCilindro = volumePeca;
                    }

                break;
            }

            if(volumePeca > maiorVolume){   //verificando se o volume inserido é o maior volume de todos
                maiorVolume = volumePeca;
            }

            system("CLS || Clear");
            printf("\nQual material da peça?\n1 - Aço\n2 - Alumínio\n3 - Cobre\n");
            materialPeca = verificaDados(1,3);

            switch(materialPeca){
                case 1:
                    pesoPeca = volumePeca * 7.8;            // calculando peso e o consumo de tinta total
                    consumoTinta += ceil(areaPeca * 0.02);

                    if(tipoPeca == 1){      //caso for uma esfera, vai ser adicionado +1 ao vetor de contador de esferas de cada tipo e o peso sera
                        contEsferas[0]++;   //armazenado em 1 vetor para armazenar os pesos de cada tipo de esferas
                        pesoEsferas[0] += pesoPeca;
                    }

                    maioresPesos[0] = maiorPeso(pesoPeca,maioresPesos,materialPeca);    //chamada da função para cálculo do maior peso

                    if(menoresVolumes[0] == 0)
                        menoresVolumes[0] = volumePeca;

                    if(pesoPeca > maioresVolumes[0])
                        maioresVolumes[0] = volumePeca;     //verificando qual o maior e menor volume de cada tipo de material
                    else
                        if(pesoPeca < menoresVolumes[0])
                            menoresVolumes[0] = volumePeca;

                break;

                case 2:
                    pesoPeca = volumePeca * 2.6;
                    consumoTinta += ceil(areaPeca * 0.01);

                    if(tipoPeca == 1){
                        contEsferas[1]++;
                        pesoEsferas[1] += pesoPeca;
                    }

                    maioresPesos[1] = maiorPeso(pesoPeca,maioresPesos,materialPeca);

                    if(menoresVolumes[1] == 0)
                        menoresVolumes[1] = volumePeca;

                    if(pesoPeca > maioresVolumes[1])
                        maioresVolumes[1] = volumePeca;
                    else
                        if(pesoPeca < menoresVolumes[1])
                            menoresVolumes[1] = volumePeca;
                break;

                case 3:
                    pesoPeca = volumePeca * 8.8;
                    consumoTinta += ceil(areaPeca * 0.015);

                    if(tipoPeca == 1){
                        contEsferas[2]++;
                        pesoEsferas[2] += pesoPeca;
                    }

                    maioresPesos[2] = maiorPeso(pesoPeca,maioresPesos,materialPeca);

                    if(menoresVolumes[2] == 0)
                        menoresVolumes[2] = volumePeca;

                    if(pesoPeca > maioresVolumes[2])
                        maioresVolumes[2] = volumePeca;
                    else
                        if(pesoPeca < menoresVolumes[2])
                            menoresVolumes[2] = volumePeca;
                break;
            }

            pesoTotal += pesoPeca;  //variavel acumuladora para calcular peso total


            system("CLS || Clear");
            printf("\nQual a loja que você comprou?");
            printf("\n1 - Casa Zé\n2 - Casa Paulo\n3 - Casa João\n4 - Casa Chico\n5 - Casa Mané\n6 - Casa Alfa\n7 - Casa Beta\n");
            lojaComprou = verificaDados(1,7);

            switch(lojaComprou){
                case 1:
                    switch(materialPeca){
                        case 1:
                            precoLoja[0] += pesoPeca * 100; //calculando o preço a ser pago a loja dependendo do tipo de material comprado
                        break;

                        case 2:
                            precoLoja[0] += pesoPeca * 80;  //Casa Zé
                        break;

                        case 3:
                            precoLoja[0] += pesoPeca * 130;
                        break;
                    }
                    switch(tipoPeca){       //verificando qual tipo de peça foi comprada em cada loja
                        case 1:
                            esferas[0]++;
                        break;

                        case 2:
                            paralelepipedos[0]++;
                        break;

                        case 3:
                            cilindros[0]++;
                        break;
                    }


                    precoTotal += precoLoja[0]; //adicionando o valor gasto por cada loja ao preço total
                break;

                case 2:
                    switch(materialPeca){
                        case 1:
                            precoLoja[1] += pesoPeca * 110;     //Casa Paulo
                        break;

                        case 2:
                           precoLoja[1] += pesoPeca * 75;
                        break;

                        case 3:
                            precoLoja[1] += pesoPeca * 120;
                        break;
                    }
                    switch(tipoPeca){
                        case 1:
                            esferas[1]++;
                        break;

                        case 2:
                            paralelepipedos[1]++;
                        break;

                        case 3:
                            cilindros[1]++;
                        break;
                    }

                    precoTotal += precoLoja[1];
                break;

                case 3:
                    switch(materialPeca){
                        case 1:
                            precoLoja[2] += pesoPeca * 150;     //Casa João
                        break;

                        case 2:
                            precoLoja[2] += pesoPeca * 90;
                        break;

                        case 3:
                            precoLoja[2] += pesoPeca * 115;
                        break;
                    }
                    switch(tipoPeca){
                        case 1:
                            esferas[2]++;
                        break;

                        case 2:
                            paralelepipedos[2]++;
                        break;

                        case 3:
                            cilindros[2]++;
                        break;
                    }

                    precoTotal += precoLoja[2];
                break;

                case 4:
                    switch(materialPeca){
                        case 1:
                            precoLoja[3] += pesoPeca * 110;     //Casa Chico
                        break;

                        case 2:
                            precoLoja[3] += pesoPeca * 100;
                        break;

                        case 3:
                            precoLoja[3] += pesoPeca * 160;
                        break;
                    }
                    switch(tipoPeca){
                        case 1:
                            esferas[3]++;
                        break;

                        case 2:
                            paralelepipedos[3]++;
                        break;

                        case 3:
                            cilindros[3]++;
                        break;
                    }


                    precoTotal += precoLoja[3];
                break;

                case 5:
                    switch(materialPeca){
                        case 1:
                            precoLoja[4] += pesoPeca * 110;     //Casa Mané
                        break;

                        case 2:
                            precoLoja[4] += pesoPeca * 50;
                        break;

                        case 3:
                            precoLoja[4] += pesoPeca * 160;
                        break;
                    }

                    switch(tipoPeca){
                        case 1:
                            esferas[4]++;
                        break;

                        case 2:
                            paralelepipedos[4]++;
                        break;

                        case 3:
                            cilindros[4]++;
                        break;
                    }

                    precoTotal += precoLoja[4];
                break;

                case 6:
                    switch(materialPeca){
                        case 1:
                            precoLoja[5] += pesoPeca * 90;     //Casa Alfa
                        break;

                        case 2:
                            precoLoja[5] += pesoPeca * 50;
                        break;

                        case 3:
                            precoLoja[5] += pesoPeca * 110;
                        break;
                    }
                    switch(tipoPeca){
                        case 1:
                            esferas[5]++;
                        break;

                        case 2:
                            paralelepipedos[5]++;
                        break;

                        case 3:
                            cilindros[5]++;
                        break;
                    }

                    precoTotal += precoLoja[5];
                break;

                case 7:
                    switch(materialPeca){
                        case 1:
                            precoLoja[6] += pesoPeca * 140;     //Casa Beta
                        break;

                        case 2:
                           precoLoja[6] += pesoPeca * 100;
                        break;

                        case 3:
                           precoLoja[6] += pesoPeca * 180;
                        break;
                    }
                    switch(tipoPeca){
                        case 1:
                            esferas[6]++;
                        break;

                        case 2:
                            paralelepipedos[6]++;
                        break;

                        case 3:
                            cilindros[6]++;
                        break;
                    }

                    precoTotal += precoLoja[6];
                break;
            }

            system("CLS || Clear");
        }
        else{
            system("CLS || Clear");
            printf("\nSaindo do programa...\n\n");
            system("Pause");
        }





    }while(tipoPeca != 0);

    latasTinta[0] = (int)consumoTinta / 10;     //Calculando quantas latas de tintas vão ser necessárias e o preço a ser pago por cada lata de tinta
    precoTotal += latasTinta[0] * 120.5;

    latasTinta[1] = (int)consumoTinta % 10 / 4;
    precoTotal += latasTinta[1] * 70.25;

    latasTinta[2] = (int)consumoTinta % 10 % 4 / 1;
    precoTotal += latasTinta[2] * 30.85;

    system("CLS || Clear");

    printf("\nExibindo relatório das lojas...\n\n");    //Exibe primeiro o relatório de cada loja e depois as outras informações necessárias
    system("Pause");                                    //O número antes de cada informação serve para mostrar qual pergunta do TP está sendo respondida
    system("CLS || Clear");

    printf("\nCasa Zé\n");
    printf("--------------------------\n");
    printf("\n7 - A loja de Zé faturou R$%.2f\n",precoLoja[0]);
    pecasLojas(esferas,paralelepipedos,cilindros,0);

    printf("\nCasa Paulo\n");
    printf("--------------------------\n");
    printf("\n7 - A loja de Paulo faturou R$%.2f\n",precoLoja[1]);
    pecasLojas(esferas,paralelepipedos,cilindros,1);

    printf("\nCasa João\n");
    printf("--------------------------\n");
    printf("\n7 - A loja de João faturou R$%.2f\n",precoLoja[2]);
    pecasLojas(esferas,paralelepipedos,cilindros,2);

    printf("\nCasa Chico\n");
    printf("--------------------------\n");
    printf("\n7 - A loja de Chico faturou R$%.2f\n",precoLoja[3]);
    pecasLojas(esferas,paralelepipedos,cilindros,3);

    printf("\nCasa Mané\n");
    printf("--------------------------\n");
    printf("\n7 - A loja de Mané faturou R$%.2f\n",precoLoja[4]);
    pecasLojas(esferas,paralelepipedos,cilindros,4);

    printf("\nCasa Alfa\n");
    printf("--------------------------\n");
    printf("\n7 - A loja de Alfa faturou R$%.2f\n",precoLoja[5]);
    pecasLojas(esferas,paralelepipedos,cilindros,5);

    printf("\nCasa Beta\n");
    printf("--------------------------\n");
    printf("\n7 - A loja de Beta faturou R$%.2f\n",precoLoja[6]);
    pecasLojas(esferas,paralelepipedos,cilindros,6);

    for(int i = 0; i <= 6; i++){
        if(precoLoja[i] > lojaMaisFaturou){
            lojaMaisFaturou = precoLoja[i];
        }
    }
    if(lojaMaisFaturou == 0)
        printf("\n12 - Nenhuma loja teve faturamento\n\n");
    else
        if(lojaMaisFaturou == precoLoja[0])
            printf("\n12 - A loja que mais faturou foi a Casa Zé\n\n");
        else
            if(lojaMaisFaturou == precoLoja[1])
                printf("\n12 - A loja que mais faturou foi a Casa Paulo\n\n");
            else
                if(lojaMaisFaturou == precoLoja[2])
                    printf("\n12 - A loja que mais faturou foi a Casa João\n\n");
                else
                    if(lojaMaisFaturou == precoLoja[3])
                        printf("\n12 - A loja que mais faturou foi a Casa Chico\n\n");
                    else
                        if(lojaMaisFaturou == precoLoja[4])
                            printf("\n12 - A loja que mais faturou foi a Casa Mané\n\n");
                        else
                            if(lojaMaisFaturou == precoLoja[5])
                                printf("\n12 - A loja que mais faturou foi a Casa Alfa\n\n");
                            else
                                printf("\n12 - A loja que mais faturou foi a Casa Beta\n\n");


    system("Pause");
    system("CLS || Clear");




    printf("\n11 - O preço total a ser pago é de R$%.2f\n",precoTotal);
    printf("\n6 - Quantidade necessária de latas de tinta:\n");
    printf("\n    Latas de 10L = %i\n",latasTinta[0]);
    printf("    Latas de 4L = %i\n",latasTinta[1]);
    printf("    Latas de 1L = %i\n",latasTinta[2]);
    printf("\n\n2 - O maior peso de aço é %.2fG\n",maioresPesos[0]);
    printf("\n\n2 - O maior peso de alumínio é %.2fG\n",maioresPesos[1]);
    printf("\n\n2 - O maior peso de cobre é %.2fG\n",maioresPesos[2]);
    printf("\n\n1 - O peso total da estátua é de %.2lf KG\n",(float)pesoTotal / 1000);

    esferasOuNao(pesoEsferas,contEsferas,0);    //chamada da função para verificar se há ou não esferas compradas
    esferasOuNao(pesoEsferas,contEsferas,1);    //e caso tenha, exibir o peso de cada tipo específico
    esferasOuNao(pesoEsferas,contEsferas,2);

    printf("\n\n3 - O maior e menor volume de aço são respectivamente: %.2fcm³ %.2fcm³\n",maioresVolumes[0],menoresVolumes[0]);
    printf("\n\n3 - O maior e menor volume de alumínio são respectivamente: %.2fcm³ %.2fcm³\n",maioresVolumes[1],menoresVolumes[1]);
    printf("\n\n3 - O maior e menor volume de cobre são respectivamente: %.2fcm³ %.2fcm³\n",maioresVolumes[2],menoresVolumes[2]);
    printf("\n\n10 - O maior volume dos cilindros é de %.2lfcm³\n",maiorVolumeCilindro);
    printf("\n\n8 - O maior volume encontrado é de %.2lfcm³\n",maiorVolume);



    return 0;
}
