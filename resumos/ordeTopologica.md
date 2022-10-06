# Ordenação topologica
Busca fazer uma ordenação dos grafos
É uma ordenação linear do grafo que esta todo `miguez`, mangue,

## Objetivo principal
- Pegar o grafo
- Ordenar linearmente em uma lista ligada

## Funcionamento
### Onde funciona ?
Só funciona para grafos aciclicos(sem ciclos) e direcionados(digrafos)
### Dicas
Sempre comece com vertices de grau de entrada = 0

### ALgoritmo
1 - Realize o busca em profundidade para achar o tempo de termino de cada vertice
2 - A medida que cada vertice é terminado, coloque-o na frente em uma lista ligada
3 - retorne essa lista

