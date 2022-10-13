// Func. obter o n-ésimo elemento da sequência de Fibonacci,
// considerando, neste caso, que se inicia em 0.
fn fibo(nth: u32) -> u64 {
    let mut a: u32 = 0;
    let mut b: u32 = 1;
    for _i in 1..nth {
        a = 2*b + a;
        b = a - b;
        a = a - b;
    }
    b.into()
}

fn main() {
    println!("{}", fibo(5));
    println!("{}", fibo(6));
    println!("{}", fibo(7));
}
