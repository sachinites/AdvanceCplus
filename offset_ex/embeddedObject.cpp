#include <stddef.h>
#include <stdio.h>

typedef struct glthread_ {
    struct glthread_ *left;
    struct glthread_ *right;
} glthread_t;

class Complex_no {

    public:
        int a;
        int b;
        glthread_t glue;
        Complex_no(int a, int b);
        static Complex_no *glthread_to_object(glthread_t *glnode);
        void print_complex_no();
        static void static_print_complex_no(Complex_no *com);
};

void
Complex_no::print_complex_no( ) {

    printf ("complex no = %d + i%d\n", this->a, this->b);
}

void
Complex_no::static_print_complex_no(Complex_no *com ) {

    printf ("complex no = %d + i%d\n", com->a, com->b);
}

Complex_no::Complex_no(int a, int b) {

    this->a = a;
    this->b = b;
    this->glue.left = NULL;
    this->glue.right = NULL;
}

Complex_no *
Complex_no::glthread_to_object(glthread_t *glnode) {

   // size_t offset = (size_t) (&Complex_no::glue);
    int offset = offsetof(Complex_no, glue);
    return (Complex_no *)((unsigned char *)glnode - offset);
}

typedef void (Complex_no::*print_fn_ptr)( );
typedef void (Complex_no::*static_print_fn_ptr)(Complex_no * );
typedef void (*global_static_print_fn_ptr)(Complex_no * );

int
main(int argc, char **argv) {

    Complex_no com1(2, 3);
    print_fn_ptr print;
    Complex_no *ptr = Complex_no::glthread_to_object(&com1.glue);
    printf ("Addr1 = %p, Addr2 = %p\n", &com1, ptr);
    print = &Complex_no::print_complex_no;
    (com1.*print)();
    static_print_fn_ptr static_print;
    //static_print = &Complex_no::static_print_complex_no;
    global_static_print_fn_ptr global_print;
    global_print = &Complex_no::static_print_complex_no;
    global_print(&com1);
    return 0;
}
