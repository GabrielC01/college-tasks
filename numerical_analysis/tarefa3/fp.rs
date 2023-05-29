/* Método do ponto fixo. */
// Parâmetros: função, valor inicial, tolerância, número máximo de iterações.
// Retorno: Ou nulo ou uma tupla com a convergência e o número de iterações.
fn fp(g: &dyn Fn(f64) -> f64, x0: f64, tolerance: f64, maxiter: i32) -> Option<(f64, i32)> {
    let mut iter = 0;
    let mut error = None;
    let mut x_prev = x0;
    let mut x_curr = x_prev;

    while error == None || error > Some(tolerance) && iter < maxiter {
        iter = iter + 1;
        x_curr = g(x_prev);
        error = Some(f64::abs(x_curr - x_prev));
        x_prev = x_curr;
    }

    if x_curr != x0 {
        Some((f64::abs(x_curr), iter))
    } else {
        None
    }
}

fn main() {
    // F1
    let f1 = |x: f64| f64::exp(-x.powi(2)) - f64::cos(x);
    let g1 = |x: f64| f64::acos(f64::exp(-x.powi(2)));
    let mut res = fp(&g1, 1.5, 10.0_f64.powi(-7), 20);

    if res == None {
        println!("Não foi possível convergir.\n");
    } else {
        println!("x: \t\t{}", res.unwrap().0);
        println!("f(x): \t\t{}", f64::abs( f1(res.unwrap().0) ));
        println!("Iterações: \t{}", res.unwrap().1);
        println!();
    }

    // F2
    let f2 = |x: f64| x.powi(3) - x - 1.0;
    let g2 = |x: f64| f64::cbrt(1.0+x);
    res = fp(&g2, 0.5, 10.0_f64.powi(-5), 20);

    if res == None {
        println!("Não foi possível convergir.\n");
    } else {
        println!("x: \t\t{}", res.unwrap().0);
        println!("f(x): \t\t{}", f64::abs( f2(res.unwrap().0) ));
        println!("Iterações: \t{}", res.unwrap().1);
        println!();
    }
    
    // F3
    let f3 = |x: f64| x.powi(3) - 9.0*x + 2.0;
    let g3 = |x: f64| (2.0 + x.powi(3)) / 9.0;
    res = fp(&g3, 0.5, 10.0_f64.powi(-10), 20);
    
    if res == None {
        println!("Não foi possível convergir.\n");
    } else {
        println!("x: \t\t{}", res.unwrap().0);
        println!("f(x): \t\t{}", f64::abs( f3(res.unwrap().0) ));
        println!("Iterações: \t{}", res.unwrap().1);
        println!();
    }
}
