/*
 * Simulador de Distin��o de Elementos
 *
 * File: Utils.cpp
 *
 * Created on: 26/06/2014
 *    Authors: Alexandre Santiago de Abreu
 *             Matheus Manzoli Ferreira
 *
 *      Email: alexandresantiago@id.uff.br
 *             matheusmanzoli@gmail.com
 *
 * Trabalho de Monografia para a 
 * Universidade Federal Fluminense.
 * Instituto de Computa��o.
 * Niter�i, Rio de Janeiro, Brasil.
 *
 * Este arquivo cont�m m�todos �teis usadas no
 * Simulador de Distin��o de Elementos.
 */

#include "Library.h"

/*
 * Construtor da Classe Utils
 */
Utils::Utils() {
    binomialCoefficients = NULL;
}

/*
 * Destrutor da Classe Utils
 */
Utils::~Utils() {
    if(binomialCoefficients != NULL)
        free(binomialCoefficients);
}

/*
 * Combinatorial
 * http://www.ebah.com.br/content/ABAAAfTVEAG/tabela-coeficientes-binomiais
 * http://www.brpreiss.com/books/opus5/html/img1869.gif
 *
 * M�todo que calcula o Coeficiente Binomial, utilizada 
 * na Combina��o
 *
 * Par�metros:
 * n = tamanho do conjunto
 * s = tamanho do subconjunto
 *
 * Computational Complexity:
 * O((n^2 - n)/2)
 * O(n^2)
 */
unsigned int Utils::combinatorial(int n, int s) {
    if(n == 0)
        return 1;

    if(binomialCoefficients != NULL && binomialCoefficients[1] == n)
        return binomialCoefficients[s];
		
    if(binomialCoefficients != NULL)
        free(binomialCoefficients);
	
    binomialCoefficients = (unsigned int *) malloc(sizeof(unsigned int) * (n+1));
    binomialCoefficients[0] = 1;
    for(int i = 1; i <= n; i++) {
        binomialCoefficients[i] = 1;
        for(int j = i - 1; j > 0; j--) {
            binomialCoefficients[j] += binomialCoefficients[j - 1];
        }
    }

    return binomialCoefficients[s];
}

/*
 * Calculate Position
 *
 * Calcula a nova posi��o para a mudan�a do estado de Hilbert H.
 * Calcula tanto a mudan�a de H para H', quanto o inverso.
 *
 * Par�metros:
 * S = 
 * initialPositionS = 
 * N = tamanho total dos valores
 * r = tamanho do subconjunto
 * previousS = 
 *
 * Computational Complexity:
 * O()
 * O()
 */
int Utils::calculate_position(vector<int> S, int initialPositionS, int N, int r, int previousS) {
    int t = 0;
    for(int i = previousS + 1; i <= S[initialPositionS] - 1; i++)
        t = t + combinatorial(N-i, r-1);
    if(r == 2)
        return S[initialPositionS+1] - S[initialPositionS] - 1 + t;
    else{
        int t1 = calculate_position(S, initialPositionS + 1, N, r - 1, S[initialPositionS]);
        return t + t1;
    }
}

/*
 * Set Intersection
 *
 * Calcula a interse��o de dois conjuntos
 *
 * Par�metros:
 * set1 = conjunto 1
 * set2 = conjunto 2
 *
 * Computational Complexity:
 * s1 = tamanho de set1 ==>  s1 <= N
 * s2 = tamanho de set2 ==>  s2 == r
 * O(N*r)
 */
set<int> Utils::set_intersection(set<int> set1, set<int> set2) {
    set<int> result;
    set<int>::iterator current = set1.begin(),
                           end = set1.end();

    for(; current != end; current++) {
        if(set2.find(*current) != set2.end())
            result.insert((*current));
    }

    return result;
}