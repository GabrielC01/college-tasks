use std::io;

// Proc. ler inteiro da entrada padrão
fn read_int() -> Result<i32, bool> {
    let sc = io::stdin();
    let mut str_input = String::new();
    sc.read_line(&mut str_input);
    return match str_input.parse::<i32>() {
        Ok(n) => Ok(n),
        Err(..) => Err(false),
    }
}

// Func. obter o n-ésimo elemento da sequência de Fibonacci
fn fibo(nth: i32) -> i64 {
    if nth <= 2 {
        return 1;
    } else {
        return fibo(nth - 1) + fibo(nth - 2);
    }
}

fn main() {
    println!("{}", fibo(16));
}
