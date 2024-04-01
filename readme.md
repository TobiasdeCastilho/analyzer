# Analisador léxico e sintático

> [!NOTE]
> O código neste repositório é uma implementação simples e inicial de um analisador léxico e sintático, e foi desenvolvido com intuíto de atender um desafio na disciplina `Conceitos de linguagem de programação`

# Como compilar o projeto

> [!NOTE]
> Utilize o shel scrit `build` na pasta raiz, será gerado na pasta `out/` o arquivo `analyzer`

# Utilização

## Argumentos

> [!NOTE]
>
> - `-f`: Deve ser seguido do arquivo que será analisado
> - `-o`: Deve ser seguido de um caminho para um arquivo de saída, nele será escrito o lexema extraído do arquivo de entrada
> - `-s`: Silencia os logs, de forma que a única resposta exibida no `stdout` serão erros
>
> ### Argumentos adicionais
>
> - `-h`: Exibe ajuda
> - `-r`: Exibe a expressão regular que será usada sobre o lexama

```sh
analyzer -f <arquivo\> -o <arquivo>.out
```

```sh
analyzer -s -f <arquivo> -o <arquivo>.out
```

##

## A fazer

> [!NOTE]
>
> - [x] Primeira versão
> - [ ] Verificar erro de remoção de `\t`
> - [ ] Nova versão - Adicionar outras entradas válidas e alterar a gramática
