#include <stdio.h>
#include <stdlib.h>


int  *convert_int_to_binary(int number, int mask, int binary_length)
{
        int *bits = (int *)malloc(binary_length*sizeof(int));
        int mask_shifted = 0;
        int number_and_mask = 0;
        for (int i = 0; i < binary_length; ++i)
        {
                mask_shifted = mask << i;
                number_and_mask = number & mask_shifted;
                bits[i] = number_and_mask >> i;
        }
        mask_shifted = 0;
        number_and_mask = 0;
        return bits;
}

int pow(int *tab0, int *tab1, int tabs_length)
{
        int res = tab0[0];
        int tmp = 0;
        for(int i = 1; i < tabs_length; i++)
        {
                tmp += tab0[i] + tab1[i];
        }
        tmp += tab1[0];
        res *= tmp;
        free(tab0);
        free(tab1);
        return res;
}



int main(int argc, char *argv[])
{
        int *number_in_binary0 = convert_int_to_binary(8, -1, 32);
        int *number_in_binary1 = convert_int_to_binary(8, 1, 32);
        int res = pow(number_in_binary0, number_in_binary1, 32);
        printf("%d\n", res);
        return 0;
}
