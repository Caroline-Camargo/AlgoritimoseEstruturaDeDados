# AlgoritimoseEstruturaDeDados
## Trabalho Prático 03  

Email para contado: caroline.sc@inf.ufpel.edu.br

NOME: <br> Caroline Souza Camargo

REGRA DE CÓDIGO LEGÍVEL: <br> Stanford Style Guide

EXERCÍCIO: <br>
Preencher uma árvore binária de busca e depois que parar de adicionar nodos dizer se é AVL ou não


LINK PARA O GIT: <br> 
https://github.com/Caroline-Camargo/AlgoritimoseEstruturaDeDados/tree/master/TrabalhoPratico3

LINK PARA O VÍDEO: <br> 
https://drive.google.com/file/d/1SoLlSh2ZO-wZr9PyG3Q3MyJIMqqWyWFT/view?usp=sharing

O QUE FUNCIONA: <br> Após vários testes com várias entradas e testando com o debugador e o Dr Memory o programa funcionou corretamente

O QUE NÃO FUNCIONA: <br> Durante o período da aula foi esquecido de alguns detalhes e alguns erros foram encontrados no código
Na função de testar a altura tinha um erro que no momento de calcular a altura da subárvore à direita eu estava chamando uma recursão para a esquerda em vez de ser uma recursão para direita
Me esqueci de testar o caso em que o nodo passado para função era um endereço inválido (NULL) na função do fator de balanceamento
No momento de verificar se o fator de balanceamento estava fora do intervalo, ou seja, ser menor que -1 e maior que 1, coloquei um && ao invés de um || (Nunca ia entrar no if, pois não tem como um número ser  menor que -1 e maior que 1 ao mesmo tempo)
Não deu tempo de implementar a função de Clear durante o período da aula, apesar de não ser um requisito necessário, pois ao encerrar o programa o correto é dar free para todos nodos alocados durante a execução.
Todos problemas foram resolvidos

