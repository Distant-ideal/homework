/*************************************************************************
	> File Name: my_printf.c
	> Author: gongpixi
	> Mail: 1371854096@qq.com
	> Created Time: 2018年09月20日 星期四 20时29分03秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <inttypes.h>

int my_printf(const char *frm, ...) {
    int cnt = 0, h = 0;
    va_list arg;
    va_start(arg, frm);
    for (int i = 0, cnt = 0; frm[i]; i++, cnt++) {
        switch (frm[i]) {
            case '%' : {
                i++;
                switch(frm[i]) {
                    case 'd' : {
                        int s = 0;
                        long long int temp = va_arg(arg, int), x = 0;
                        if(temp < 0) {
                            temp *= -1;
                            h = 1;
                        }
                        while (temp) {
                            if(temp % 10 == 0)  {
                                s++;
                            }
                            x = x * 10 + temp % 10;
                            temp /= 10;
                        }
                        if(h == 1) {
                            putchar('-');
                        }
                        while (x) {
                            putchar(x % 10 + '0');
                            x /= 10; 
                        }
			            if(s != 0) {
                            for(int k = 1; k <= s; k++) {
                                putchar(0 + '0');
                            }
                        }
                        
                    } break;
                    default : 
                        fprintf(stderr, "error : unknow %%%c\n", frm[i]); 
                        exit(1);
                }
            } break;
            default:
            putchar(frm[i]);
        }
    }
    return cnt;
}

int main() {
    int n = 123;
    my_printf("hello world\n");
    my_printf("n = %d\n", n);
    my_printf("n = %d\n", 12000);
    my_printf("n = %d\n", -567);
    my_printf("n = %d\n", INT32_MIN);
    my_printf("n = %d\n", INT32_MAX);
    return 0;
}
