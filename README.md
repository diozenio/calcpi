# Cálculo de PI usando Threads

O Cálculo de PI usando Threads é um projeto desenvolvido para a disciplina de Sistemas Operacionais, do 3° período de Sistemas de Informação do Instituto Federal de Alagoas - Campus Arapiraca, ministrada pelo docente Fernando Antônio.

| Integrantes                     | E-mails Institucionais  |
| ------------------------------- | ----------------------- |
| Dionísio Barbosa da Silva Leite | dbsl1@aluno.ifal.edu.br |
| Maria Izabel da Silva Lemos     | mils2@aluno.ifal.edu.br |
| Pedro Henrique Bastos de Brito  | phbb1@aluno.ifal.edu.br |
| Ray Antoniel Silva Santos       | rass3@aluno.ifal.edu.br |
| Thiago de Almeida Pereira Filho | tapf1@aluno.ifal.edu.br |

# Objetivo

O objetivo desse projeto é compreender melhor sobre o conceito de threads e explorar as melhores práticas do seu gerenciamento com base no poder de processamento disponível nos computadores modernos. Com isso, foi solicitado o desenvolvimento de um algoritmo para o cálculo do número de PI utilizando N threads simultâneas, tendo o seu resultado aproximado pela **série de Leibniz-Grégory**.

# Resultados

A seção corrente apresenta os resultados obtidos pela equipe ao longo da execução do projeto. É importante ressaltar que os testes foram processados no sistema operacional Windows 11 e conduzidos utilizando um processador Intel Core i5-13400F, operando a uma frequência de 2.5GHz e com capacidade para 16 threads. Além disso, como fora solicitado, os experimentos foram efetuados utilizando 1 bilhão de termos da **série de Leibniz-Grégory**.

| Número de Threads | Tempo de Execução | Resultado         |
| ----------------- | ----------------- | ----------------- |
| 1                 | 95.329s           | 3.141592652587899 |
| 2                 | 48.484s           | 3.141592652589406 |
| 4                 | 24.879s           | 3.141592652589255 |
| 8                 | 13.309s           | 3.141592652589357 |
| 16                | 8.159s            | 3.141592652590253 |

# Discussões

A seção corrente está destinada à discussão de questionamentos apontados pelo docente como requisito avaliativo do projeto.

A princípio, o código utiliza o escalonamento preemptivo, gerido pelo sistema operacional, implementado através da diretiva `#pragma omp parallel for num_threads(num_threads) reduction(+:pi)` da biblioteca OpenMP. Assim sendo, o sistema operacional aloca as threads aos processadores físicos e as gerencia de forma preemptiva, podendo interrompê-las e alternar entre elas para garantir um uso justo da CPU. Além do mais, é válido pontuar que as threads podem terminar em tempos diferentes, dependendo da duração de suas tarefas.

Por fim, o modelo de threads implementado, com base no sistema operacional utilizado para a execução do projeto, é **one-to-one**. Cada thread gerada pela diretiva OpenMP será mapeada para uma thread de kernel, permitindo que o sistema operacional gerencie e escalone essas threads de forma eficiente e preemptiva.

# Run

```bash
  gcc -o main.exe main.c -lm -fopenmp; ./main.exe
```
