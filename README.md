# RIprojectNearestString

Projekat iz predmeta Racunarska Inteligencija. Tema projekta je NP tezak problem Nearest string.
[Link ka problemu](https://www.csc.kth.se/~viggo/wwwcompendium/node258.html#8078).

## Brute Force
Implementacija brute force algoritma koji resava ovaj problem. U sklopu resenja postoji i klasa makeBigFile koja sluzi za generisanje fajla za testiranje programa. Fajl se nalazi u datoteci resources.

### Pokretanje brute force algoritma
```
cd BruteForce
cd src
g++ bruteForce.cpp
./a.out
```
## Optimization algorithm
Optimizacija je uradjena koriscenjem RVNS-a i simuliranog kaljenja. Sto se tice testiranja isto vazi kao i za brute force algoritam.

### Pokretanje optimizacionog algoritma
```
cd OptimizationAlgorithm
cmake .
make
./OptimizationAlgorithm
```
