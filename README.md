# 🔄 Push_Swap

> Un progetto 42 per ordinare una pila di numeri utilizzando un set limitato di operazioni, ottimizzando il numero di mosse.

[![42 Badge](https://img.shields.io/badge/42-push__swap-success)](https://42.fr)

## 📋 Indice

- [Descrizione](#-descrizione)
- [Operazioni Disponibili](#-operazioni-disponibili)
- [Algoritmo Utilizzato](#-algoritmo-utilizzato)
- [Ottimizzazioni Implementate](#-ottimizzazioni-implementate)
- [Performance](#-performance)
- [Compilazione e Utilizzo](#-compilazione-e-utilizzo)
- [Struttura del Progetto](#-struttura-del-progetto)

## 📖 Descrizione

**Push_swap** è un progetto che richiede di ordinare una pila di numeri interi utilizzando due pile (A e B) e un set limitato di operazioni. L'obiettivo è ordinare la pila A in ordine crescente con il **minor numero possibile di operazioni**.

## 🎮 Operazioni Disponibili

| Operazione | Descrizione |
|------------|-------------|
| `sa` | Swap dei primi due elementi della pila A |
| `sb` | Swap dei primi due elementi della pila B |
| `ss` | `sa` e `sb` contemporaneamente |
| `pa` | Push del primo elemento da B in cima ad A |
| `pb` | Push del primo elemento da A in cima a B |
| `ra` | Rotate A: il primo elemento diventa l'ultimo |
| `rb` | Rotate B: il primo elemento diventa l'ultimo |
| `rr` | `ra` e `rb` contemporaneamente |
| `rra` | Reverse Rotate A: l'ultimo elemento diventa il primo |
| `rrb` | Reverse Rotate B: l'ultimo elemento diventa il primo |
| `rrr` | `rra` e `rrb` contemporaneamente |

## 🧠 Algoritmo Utilizzato

### Turkish Algorithm (Cost-Based Insertion Sort)

L'algoritmo implementato è basato sul **Turkish Algorithm**, una variante ottimizzata dell'insertion sort che calcola il "costo" di ogni possibile mossa per scegliere sempre quella più efficiente.

### Fasi dell'Algoritmo

#### 1️⃣ **Fase di Push verso B** (`push_all_in_b`)

```
Stack A: [5, 3, 8, 1, 9, 2]  →  Stack A: [8, 1, 9]
Stack B: []                  →  Stack B: [2, 3, 5]
```

- Tutti gli elementi tranne 3 vengono spostati dalla pila A alla pila B
- Per pile grandi (≥200 elementi), viene applicata una **pre-ottimizzazione**: se l'elemento in cima è maggiore del successivo, viene ruotato prima del push per migliorare l'ordine parziale

#### 2️⃣ **Ordinamento dei 3 elementi rimanenti** (`order_three`)

```
Stack A: [8, 1, 9]  →  Stack A: [1, 8, 9]
```

- I 3 elementi rimasti in A vengono ordinati con un algoritmo specifico che usa al massimo 2-3 operazioni
- Utilizza combinazioni di `sa`, `ra` e `rra` basandosi sullo stato corrente

#### 3️⃣ **Fase di Re-inserimento Ottimizzato** (`push_back_in_a`)

Questa è la fase **cruciale** dell'algoritmo. Per ogni elemento in B:

1. **Trova la posizione target** (`best_element`): identifica dove l'elemento dovrebbe essere inserito in A per mantenere l'ordine
2. **Calcola i costi** (`fill_info`): calcola le rotazioni necessarie per entrambe le pile
3. **Valuta l'efficienza** (`check_efficiency`): confronta 4 strategie di movimento:
   - `rr` (rotate entrambe)
   - `rrr` (reverse rotate entrambe)
   - `ra` + `rrb` (rotate A, reverse rotate B)
   - `rra` + `rb` (reverse rotate A, rotate B)
4. **Esegue la mossa migliore** (`best_move`): seleziona l'elemento con il costo totale minore

#### 4️⃣ **Rotazione Finale** (`final_sorting`)

```
Stack A: [3, 5, 8, 1, 2]  →  Stack A: [1, 2, 3, 5, 8]
```

- Una volta che tutti gli elementi sono tornati in A, la pila potrebbe essere ordinata ciclicamente
- Trova il minimo e ruota la pila per portarlo in cima

## ⚡ Ottimizzazioni Implementate

### 1. **Calcolo del Costo Combinato**

```c
void check_efficiency(t_rotations *moves)
{
    int both_r  = max(abs(moves->ra), abs(moves->rb));    // rr
    int both_rr = max(abs(moves->rra), abs(moves->rrb));  // rrr
    int r_rr    = abs(moves->ra) + abs(moves->rrb);       // ra + rrb
    int rr_r    = abs(moves->rra) + abs(moves->rb);       // rra + rb
    
    // Seleziona la strategia con costo minimo
}
```

Invece di calcolare separatamente le rotazioni per A e B, l'algoritmo considera che:
- `rr` conta come **1 operazione** (non 2)
- `rrr` conta come **1 operazione** (non 2)

Questo permette di sfruttare le operazioni combinate per risparmiare mosse.

### 2. **Ricerca Circolare della Posizione** (`best_element`)

```c
t_list *best_element(t_list *stack_a, t_list *stack_b)
{
    // Crea temporaneamente una lista circolare
    end->next = stack_a;
    // Cerca partendo dal minimo
    copy = min;
    while (min->next != copy)
    {
        if (n1 < n2)
            return (min);  // Posizione trovata
        min = min->next;
    }
}
```

La pila viene trattata come **circolare** per trovare la posizione corretta di inserimento, gestendo correttamente i casi limite.

### 3. **Pre-ordinamento per Pile Grandi**

```c
if (len >= 200)
{
    if ((*stack_a)->number > ((*stack_a)->next)->number)
        go_for_rotation(1, 0, stack_a, stack_b);
    pb(stack_a, stack_b);
}
```

Per pile con 200+ elementi, viene applicata una rotazione preventiva quando l'elemento corrente è maggiore del successivo, riducendo il disordine durante il push.

### 4. **Esecuzione Ottimizzata delle Rotazioni** (`go_for_rotation`)

```c
void go_for_rotation(int rtsa, int rtsb, t_list **stack_a, t_list **stack_b)
{
    // Prima: rotazioni combinate (risparmiano mosse)
    while (rtsa < 0 && rtsb < 0) rrr(...);
    while (rtsa > 0 && rtsb > 0) rr(...);
    
    // Poi: rotazioni singole residue
    while (rtsa < 0) rra(...);
    while (rtsb < 0) rrb(...);
    while (rtsa > 0) ra(...);
    while (rtsb > 0) rb(...);
}
```

Le rotazioni vengono eseguite dando **priorità alle operazioni combinate**, massimizzando il risparmio di mosse.

## 📊 Performance

| Numero di elementi | Mosse (media) | Obiettivo 42 |
|-------------------|---------------|--------------|
| 3 | ≤ 3 | ≤ 3 |
| 5 | ≤ 12 | ≤ 12 |
| 100 | ~700 | < 700 (5 punti) |
| 500 | **< 5500** ✅ | < 5500 (5 punti) |

### Perché funziona per 500 numeri?

L'algoritmo raggiunge meno di **5500 mosse** grazie a:

1. **Complessità ridotta**: O(n²) nel caso peggiore, ma con costanti molto basse
2. **Sfruttamento di `rr` e `rrr`**: ogni operazione combinata risparmia ~1 mossa
3. **Scelta greedy ottimale**: ad ogni iterazione viene scelto l'elemento con il costo minimo di inserimento
4. **Gestione efficiente dei casi limite**: la ricerca circolare evita rotazioni inutili

## 🔧 Compilazione e Utilizzo

```bash
# Compilazione
make

# Esecuzione
./push_swap 4 67 3 87 23

# Conteggio mosse
./push_swap 4 67 3 87 23 | wc -l

# Test con checker (bonus)
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG

# Generare numeri casuali e testare
ARG=$(shuf -i 1-500 -n 500 | tr '\n' ' '); ./push_swap $ARG | wc -l
```

## 📁 Struttura del Progetto

```
push_swap/
├── srcs/
│   ├── main.c              # Entry point
│   ├── algorithm.c         # Core: best_move, check_efficiency
│   ├── algorithm_utils.c   # Utility: fill_info, set_rotations
│   ├── sorting.c           # Orchestrazione: push_all_in_b, push_back_in_a
│   ├── sorting_utils.c     # Utility: findmin, is_sorted, go_for_rotation
│   ├── order_three.c       # Ordinamento per 3 elementi
│   ├── check_input.c       # Parsing e validazione input
│   ├── push_swap_utils.c   # Utility generali
│   ├── push.c              # Operazioni pa, pb
│   ├── swap.c              # Operazioni sa, sb, ss
│   ├── rotate.c            # Operazioni ra, rb, rr
│   ├── reverse_rotate.c    # Operazioni rra, rrb, rrr
│   └── push_swap.h         # Header file
├── checker/                # Bonus: programma di verifica
├── libft/                  # Libreria di utility
├── Makefile
└── README.md
```

## 🎯 Conclusioni

L'implementazione del **Turkish Algorithm** con le ottimizzazioni descritte permette di:
- ✅ Ordinare 500 numeri in **meno di 5500 mosse**
- ✅ Mantenere un codice leggibile e modulare
- ✅ Gestire correttamente tutti i casi limite
- ✅ Sfruttare al massimo le operazioni combinate (`rr`, `rrr`)

---

*Progetto realizzato per il curriculum di 42.*
