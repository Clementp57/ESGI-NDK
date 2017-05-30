//
// Created by Clément Peyrabere on 29/05/2017.
//

#include <string.h>
#include <jni.h>

#define NB_OODS_INDEX 0
#define GIFT_PRICE 1

int computeAverage(int n, int leftToPay) {
    return (int) leftToPay / n;
}

int isPossible(int probleme[]) {
    int sum = 0;
    int i;
    for(i = 2; i < probleme[0] + 2; i++) {
        sum += probleme[i];
    }
    if(sum < probleme[1]) {
        return 0;
    }
    return 1;
}

int * computeGift(int probleme[]) {
    if(isPossible(probleme)){
        int * solutions = malloc(sizeof(int)*probleme[1]);
        int nbOods = probleme[NB_OODS_INDEX];
        __android_log_print("Warning", "NB OODS", "%d", nbOods);
        int leftToPay = probleme[GIFT_PRICE];
        __android_log_print("Warning", "Left to pay", "%d", leftToPay);
        int i;
        int nbSolutions = 0;
        for(i = 2; i < nbOods + 2; i++) {
            int oodsLeft = nbOods - nbSolutions;
            int average = computeAverage(oodsLeft, leftToPay);
            __android_log_print("Warning", "Average", " %d", average);
            int solution;
            if(probleme[i] < average) {
               solution = probleme[i];
            } else {
               solution = average;
            }
            __android_log_print("Warning", "Solution", " %d", solution);
            solutions[i - 2] = solution;
            nbSolutions ++;
            leftToPay = leftToPay - solution;
            __android_log_print("Warning", "LeftToPay", " %d", leftToPay);
        }

        for(int i = 0; i < nbOods; i++) {
            __android_log_print("Warning", "myGift", "%d %d", i, solutions[i]);
        }
        return solutions;
    } else {
        return NULL;
    }
}

jintArray Java_com_example_app_Main_gift ( JNIEnv* env,jobject thiz ){
    int probleme[] = { 3 , 100 , 3 , 100, 100 };
    int * solutions = computeGift(probleme);
    int size = probleme[0];

    jintArray result;
    result = (*env)->NewIntArray(env, size);
    if (result == NULL || solutions == NULL) {
        return NULL;
    }
    int i;
    jint fill[256];
    for (i = 0; i < size; i++) {
        fill[i] = solutions[i];
    }
    (*env)->SetIntArrayRegion(env, result, 0, size, fill);
    return result;
}

