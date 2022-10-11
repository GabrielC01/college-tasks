// Func. obter o n-ésimo elemento da sequência de Fibonacci,
// considerando, neste caso, que se inicia em 1.
fn fibo(nth: i32) -> i64 {
    if nth <= 1 {
        return 1;
    } else {
        return fibo(nth - 1) + fibo(nth - 2);
    }
}

fn main() {
    println!("{}", fibo(4));
}
