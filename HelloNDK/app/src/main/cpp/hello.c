//
// Created by Clément Peyrabere on 29/05/2017.
//

int fibonnaci(int n){
    if (n<=1) return 1;
    return (fibonnaci(n-1))+(fibonnaci(n-2));
}
