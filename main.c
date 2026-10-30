#include <stdio.h>
// #include "validation.h" 
#include "apc.h"


int main(int argc, char* argv[]) {
    if (validate_Number_of_CLA(argc) != 0) {
        return 1;
    }

    validate_input(argv);
    slicing_input_dll(argv);

    switch(operator) {
        case '+':
            addition(list1, list2, &res_list);
            printf("Result: ");
            print_list(res_list);
            break;
                
        case '-':
            int cmp = compare_lists(list1, list2);
            if (cmp >= 0) {
                subtraction(list1, list2, &res_list);
                printf("Result: ");
                print_list(res_list);
            } else {
                subtraction(list2, list1, &res_list);
                printf("Result: -");
                print_list(res_list);
            }
            break;
        case '*': {
            int sign1 = (argv[1][0] == '-') ? -1 : 1;
            int sign2 = (argv[3][0] == '-') ? -1 : 1;

            multiplication(list1, list2, &res_list);

            printf("Result: ");
            if (sign1 * sign2 == -1) {
                printf("-");
            }
            print_list(res_list);
            break;
        }
    case '/': {
            int sign1 = (argv[1][0] == '-') ? -1 : 1;
            int sign2 = (argv[3][0] == '-') ? -1 : 1;

            division(list1, list2, &res_list);

            if (res_list != NULL) {
                printf("Result: ");
                if (sign1 * sign2 == -1 && !(res_list->data == 0 && res_list->next == NULL)) {
                    printf("-");
                }
                print_list(res_list);
            }
            break;
        }
    }

    return 0;
}
