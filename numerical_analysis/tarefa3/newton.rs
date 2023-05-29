/* Função do método de Newton-Raphson. */
// Parâmetros: função, derivada da função, aproximação inicial, tolerância e número
// máximo de iterações.
// Retorno: Ou a solução aproximada ou nulo.
fn newton(f: &dyn Fn(f64) -> f64, df: &dyn Fn(f64) -> f64, x0: f64, tolerance: f64, maxiter: i32)
    -> Option<(f64, i32)> {
    let mut i = 0;
    let mut error: Option<f64> = None;
    let mut x: f64 = x0;
    let mut dx: f64;
    let mut x0_cpy = x0;

    while error == None || error > Some(tolerance) && i < maxiter {
        i += 1;
        dx = - f(x0_cpy)/ df(x0_cpy);
        x = x0_cpy + dx;
        error = Some( f64::abs(x - x0_cpy) );
        x0_cpy = x;
    }

    if error > Some(tolerance) || x != x0_cpy {
        None
    } else {
        Some((x, i))
    }
}

fn main() {
    // F1
    let f1 = |x: f64| f64::exp(-x.powi(2)) - f64::cos(x);
    let df1 = |x: f64| f64::sin(x) - 2.0 * f64::exp(-x.powi(2)) * x;
    let mut res = newton(&f1, &df1, 1.5, 10.0_f64.powi(-7), 20);

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
    let df2 = |x: f64| 3.0*x.powi(2) - 1.0;
    res = newton(&f2, &df2, 0.0, 10.0_f64.powi(-5), 20);

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
    let df3 = |x: f64| 3.0*x.powi(2) - 9.0;
    res = newton(&f3, &df3, 0.0, 10.0_f64.powi(-10), 20);

    if res == None {
        println!("Não foi possível convergir.\n");
    } else {
        println!("x: \t\t{}", res.unwrap().0);
        println!("f(x): \t\t{}", f64::abs( f3(res.unwrap().0) ));
        println!("Iterações: \t{}", res.unwrap().1);
        println!();
    }
}
