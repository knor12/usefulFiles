
/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#define BIT_SET_ui64(BF, N) BF|=((uint64_t)0x1<<N)
#define BIT_CLR_ui64(BF, N) BF&=~((uint64_t)0x1<<N)

#define BIT_SET_i64(BF, N) BF|=((int64_t)0x1<<N)
#define BIT_CLR_i64(BF, N) BF&=~((int64_t)0x1<<N)

#define BIT_SET_ui32(BF, N) BF|=((uint32_t)0x1<<N)
#define BIT_CLR_ui32(BF, N) BF&=~((uint32_t)0x1<<N)

#define BIT_SET_i32(BF, N) BF|=((int32_t)0x1<<N)
#define BIT_CLR_i32(BF, N) BF&=~((int32_t)0x1<<N)

#define BIT_SET_ui16(BF, N) BF|=((uint16_t)0x1<<N)
#define BIT_CLR_ui16(BF, N) BF&=~((uint16_t)0x1<<N)

#define BIT_SET_i16(BF, N) BF|=((int16_t)0x1<<N)
#define BIT_CLR_i16(BF, N) BF&=~((int16_t)0x1<<N)

#define BIT_SET_ui8(BF, N) BF|=((uint8_t)0x1<<N)
#define BIT_CLR_ui8(BF, N) BF&=~((uint8_t)0x1<<N)

#define BIT_SET_i8(BF, N) BF|=((int8_t)0x1<<N)
#define BIT_CLR_i8(BF, N) BF&=~((int8_t)0x1<<N)

#define BIT_IS_SET(BF, N) ((BF >> N) & 0x1)

#include <stdio.h>
#include <stdint.h>

void printBinary(uint32_t in,uint32_t maxBits)
{
    int  minBits=0;
    
    for (int i =0; i< 31 ; i++)
    {
        if (BIT_IS_SET(in , i))
        {
            minBits = i+1;
        }
        
    }
    
    if (minBits==0) {minBits=1;}
    
    //printf("/* minBits=%d, maxBits=%d*/",minBits , maxBits); 
    //return;
    
    for (int j = maxBits ; j >= minBits-1 ; j-- )
    {
        //printf("j=%d\n" , j);
        printf("#define B");
        for (int h = j; h >= 0; h--)
        {
            if (BIT_IS_SET(in, h))
            {
                printf("1");
            }else 
            {
                 printf("0");
            }
        }
        printf(" %d \/*0x%x*\/\n" , in, in);
    }
    
    
}

int main()
{
    for (int i = 0; i<=0xFFFF; i++)
    {
        printBinary(i,16-1);
        printf("\n");
    }
    

}

