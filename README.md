
# Algoritmos de Ordenação em C

Este projeto em linguagem C implementa e compara o desempenho de três algoritmos clássicos de ordenação aplicados a um vetor de 20 pessoas, ordenando-as alfabeticamente pelo nome.

---

##  Estrutura de Dados

A estrutura usada para armazenar os dados é:

```c
typedef struct {
    char nome[100];
    int idade;
} Pessoa;
```

---

##  Algoritmos de Ordenação Implementados

### 1. **Bubble Sort**
- **Descrição:** Percorre o vetor várias vezes, comparando pares de elementos adjacentes e trocando-os se estiverem fora de ordem.
- **Vantagem:** Fácil de entender e implementar.
- **Desvantagem:** Extremamente ineficiente para grandes conjuntos de dados.

> **Complexidade:**
 Melhor caso: O(n)
 Médio caso: O(n²)
 Pior caso: O(n²)

---

### 2. **Insertion Sort**
- **Descrição:** Constrói uma lista ordenada gradualmente, inserindo um elemento de cada vez na posição correta.
- **Vantagem:** Eficiente para pequenos conjuntos de dados ou listas quase ordenadas.
- **Desvantagem:** Desempenho ruim em listas grandes e desordenadas.

> Complexidade:
 Melhor caso: O(n)
 Médio caso: O(n²)
 Pior caso: O(n²)

---

### 3. **Merge Sort**
- **Descrição:** Divide recursivamente o vetor em duas metades, ordena cada metade e depois as mescla.
- **Vantagem:** Estável e eficiente, mesmo para grandes conjuntos de dados.
- **Desvantagem:** Utiliza espaço adicional proporcional ao tamanho do vetor.

> **Complexidade:**
 Melhor caso: O(n log n)
 Médio caso: O(n log n)
 Pior caso: O(n log n)

---

## Resultados de Desempenho (20 pessoas)

| Algoritmo      | Comparações Médias | Trocas Médias | Tempo Médio (ms) |
|----------------|--------------------|----------------|------------------|
| Bubble Sort    | 190                | 76             | 0.0038           |
| Insertion Sort | 95                 | 76             | 0.0020           |
| Merge Sort     | 59                 | 26             | 0.0046           |

---

##  Considerações

- O algoritmo **Merge Sort** teve o menor número de comparações e trocas, mostrando eficiência teórica na prática.
- O **Insertion Sort** foi mais rápido que o **Bubble Sort**, com menos comparações.
- O tempo pode variar ligeiramente entre execuções, principalmente por ser um volume pequeno de dados.

---

##  Compilação

```bash
gcc programa.c -o programa
./programa
```

---

## Autor

Trabalho acadêmico para disciplina de Estrutura de Dados II do curso de Análise e Desenvolvimento de Sistemas, com foco na comparação de algoritmos de ordenação.
