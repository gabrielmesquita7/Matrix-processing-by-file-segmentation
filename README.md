<h1 align="center">Matrix processing by file segmentation</h1>

<p style="font-size:120%;" align="center">
    <a href="#problema">Problema</a> -
    <a href="#desenvolvimento">Desenvolvimento</a> -
    <a href="#saida">Saida</a> -
    <a href="#executar">Executar</a>

</p>

# Problema
### Neste trabalho, deve ser feito a implementação de um sistema de multiplicação de matrizes baseando-se em uma estratégia de segmentação em arquivo. Um arquivo **M** grande é fornecido no formato **NxN** com valores de ponto flutuante ou inteiros como entrada. Este é processado a partir de várias coordenadas introduzidas por um segundo arquivo, o *coordenadas.txt*. Em *coordenadas.txt* deve ser descrito por linha uma dupla de **i** e **j** correspondendo a posição inicial e final a ser lida. Por exemplo, as posições 2,4,6,10 indica que a leitura em M deve iniciar na linha 2 coluna 4 e seguir até a linha 6 coluna 10. 

### Feito a leitura da composição de **M** para um tipo matriz em C, a segunda etapa é produzir a transposta de **M -= MT**. Feito isso, produza a multiplicação e armazene em uma **hash** o resultado da multiplicação como valor para a dupla de **i's** e **j's**, os quais deverão ser utilizados como **chaves** da hash. Assim, para cada novo calculo, antes o sistema deve consular a hash para identificar se a multiplicação já foi realizada. Em caso afirmativo, retorne apenas a resposta já calculada. Caso contrário, elabore a multiplicação e armazene o conteúdo em **cache**. 

# Desenvolvimento
 Foi utilizado o **C++** devido a facilidade na manipulação de arquivos e pela vasta quantidade de estruturas já implementadas, como por exemplo a utilização da estrutura **unordered_map** que é implementada usando **Hash Table** , armazenando elementos formados pela combinação de valor-chave e um valor mapeado. 
### O problema foi desenvolvido da seguinte maneira:
* É definido pelo usuario o tamanho da **Matriz M** atribuindo o valor para **MAXTAM** na função **define**. Esse valor será utilizado para gerar a matriz **M x M**


```cpp
#define MAXTAM 10 \\matriz 10x10
```

### Funcões:

> ```cpp
> void EscreveMatrizG();
> ```
> Faz a escrita da matriz no arquivo **matriz.txt**, sendo que a cada execução do programa é gerado numeros diferentes limitados a 2 algarismos.

> ```cpp
> vector<string> tokenizer(string text);
> ```
> Função generica de tokenização que retorna um vetor de strings dos tokens armazenados de um texto

> ```cpp
> vector<int> ler_coords();
> ```
> Faz a leitura do arquivo **coordenadas.txt**, tokeniza as coordenadas e armazena em um vector que será retornado.

> ```cpp
> int **ler_matriz(int xi, int yi, int xj, int yj);
> ```
> Faz a leitura do arquivo **matriz.txt** e utiliza como parâmetros as coordenadas para efetuar os calculos que envolvem a dimensão da nova matriz e para delimitar o quadrante a ser tokenizado.
> Foi utilizado a função **getline()** com um **buffer** para deslocar entre as linhas e com a utilização de um delimitador foi feito a captura dos elementos da matriz e armazenado em um **vector** que logo depois transferiu esses valores para uma matriz **m, retornando a mesma no final da função.

> ```cpp
> int **transposta(int **matriz, int M, int N);
> ```
> Recebe uma matriz e retorna a transposta dela.

> ```cpp
> int **multiplicacao_matriz(int **matriz1, int **matriz2, int M, int N);
> ```
> Recebe duas matrizes e retorna a multiplicação entre elas.

> ```cpp
> bool verifyHash(int key, unordered_map<int, int **> hashm);
> ```
> Verifica se a hash contém a **key**: **Se sim** -> **True** ; **Se não** -> **False**

> ```cpp
> void printMatriz(int xi, int xj, int **m);
> ```
> Recebe uma matriz quadrada **M x M** e imprimi ela.

> ```cpp
> void hash_storage(int xi, int yi, int xj, int yj);
> ```
> Essa função é o core do programa, ou seja, se utiliza de todas as outras funções previamente citadas para retornar o resultado esperado. Sendo assim a primeira etapa envolve gerar uma **key** com as coordenadas recebidas, depois é feito a verificação dessa key na **Hash**: **Se já foi cadastrado**-> É informado ao usuário e printado o calculo da multiplicação armazenada; **Se não foi cadastrado**-> É feito todo o processo de criar a matriz até o armazenamento da multiplicação na hash com a nova **key**.

> ```cpp
> void readtxt();
> ```
> Função que efetua a mesma operação que a **hash_storage()** porém se utiliza das coordenadas do documento **coordenadas.txt**.


# Saida
### É esperado que o usuario seja informado do tempo em que a matriz (Ex: 10 x 10) foi gerada e seja direcionado ao seguinte menu:
![Captura de tela de 2022-09-01 17-47-20](https://user-images.githubusercontent.com/55333375/188009695-d01f6f56-14c9-4547-bdc5-a72d65bdea46.png)
### Selecionando a primeira opção o usuário é direcionado a um novo menu:
![Captura de tela de 2022-09-01 17-50-59](https://user-images.githubusercontent.com/55333375/188010154-e570a185-788b-4500-ba91-e3141767255d.png)
### Feito a escolha **0** o programa fará a leitura das coordenadas do arquivo .txt (:
![image](https://user-images.githubusercontent.com/55333375/188010591-62a40813-9cd0-41e2-a8d0-e1d2dc7af12b.png)
### Feito a escolha **1** será solicitado ao usuário as coordenadas:
![Captura de tela de 2022-09-01 17-59-16](https://user-images.githubusercontent.com/55333375/188011919-4c7cc6c1-5333-4d50-8793-3823c72feb08.png)
### Caso a coordenada (transformada em key) lida ou digitada pelo usuário for igual a alguma armazenada dentro da hash será informado com a seguinte mensagem e impresso o resultado armazenado: 
![Captura de tela de 2022-09-01 18-05-42](https://user-images.githubusercontent.com/55333375/188012977-931b0349-254a-445c-a37b-c90536b8a131.png)
### O menu será executado em loop até o usuário digitar a opção de sair.
![Captura de tela de 2022-09-01 18-09-48](https://user-images.githubusercontent.com/55333375/188013650-3b6fc63c-61f7-46a7-a2ce-0549ee160ce5.png)


# Executar
* Como executar:

<html>
<table>
    <tr>
        <td><code>make clean</code></td>
    <tr>
        <td><code>make</code></td>
    </tr>
    <tr>
        <td><code>make run</code></td>
    </tr>
    <tr>
</table>
</html>
