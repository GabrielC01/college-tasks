// Func. obter o n-ésimo elemento da sequência de Fibonacci,
// considerando, neste caso, que se inicia em 1.
fn fibo(nth: i32) -> i64 {
    let mut n = 0;
    for i in 2..=nth {
        n = i - 1 + i - 2;
    }
    n.into()
}

fn main() {
    println!("{}", fibo(4));
}
