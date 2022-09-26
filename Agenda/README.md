# AlgoritimoseEstruturaDeDados
## Trabalho AGENDA

Email para contado: caroline.sc@inf.ufpel.edu.br

NOME: <br> Caroline Souza Camargo

REGRA DE CÓDIGO LEGÍVEL: <br> Stanford Style Guide

EXERCÍCIO: <br>
PARTE 1: <br> 
    Faça uma agenda capaz de incluir, apagar, buscar e listar quantas pessoas o usuário desejar, porém, toda a informação incluída na agenda deve ficar num único lugar chamado: “void *pBuffer”.
    Não pergunte para o usuário quantas pessoas ele vai incluir. Não pode alocar espaço para mais pessoas do que o necessário. <br> 

PARTE 2:  
    Nenhuma variável pode ser declarada em todo o programa, somente ponteiros. Todos os dados do programa devem ser guardados dentro do pBuffer. Nem mesmo como parâmetro de função.  Só ponteiros que apontam para dentro do pBuffer.  <br> 
    Exemplo do que não pode: int c; char a; int v[10]; void Funcao(int parametro)
    Não pode usar struct em todo o programa. 
    Usar fila ordenada (heap) para armazenar as pessoas em ordem alfabética sempre que o usuário incluir uma nova pessoa.  Implementar a base de dados da agenda usando lista duplamente ligada <br> 
    Somente essa base de dados pode ficar fora do buffer principal, ou seja, pode usar um malloc para cada nodo.

LINK PARA O GIT: <br> 
https://github.com/Caroline-Camargo/AlgoritimoseEstruturaDeDados/tree/master/Agenda

LINK PARA O VÍDEO: <br> 
https://drive.google.com/file/d/1gqqzeF04iJJC62t95boiqla7WTUuE_cR/view?usp=sharing

O QUE FUNCIONA: <br> 
Após vários testes com várias entradas e testando com o debugador e o Dr Memory o programa funcionou corretamente

O QUE NÃO FUNCIONA: <br> 
Durante a realização do trabalho ocorreram vários erros, mas felizmente todos problemas encontrados foram solucionados. 
Entre os erros achados estam a manipulação dos ponteiros errada e casos especiais, como não existir ninguém na fila e tentar remover


