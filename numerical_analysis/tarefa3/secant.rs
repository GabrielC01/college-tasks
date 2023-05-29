/* Método da Secante. */
// Parâmetros: função, derivada da função, duas aproximações iniciais, tolerância e número
// máximo de iterações.
// Retorno: Ou a solução aproximada ou nulo.
fn secant(f: &dyn Fn(f64) -> f64, x_ini: [f64; 2], tolerance: f64, maxiter:
          i32) -> Option<(f64, i32)> {
    let mut i = 0;
    let mut error: Option<f64> = None;
    let mut x0: f64 = x_ini[0];
    let mut x1: f64 = x_ini[1];
    let mut x2 = x1;

    while error == None || error > Some(tolerance) && i < maxiter {
        i += 1;
        x2 = ( x0*f(x1) - x1*f(x0) ) / ( f(x1) - f(x0) );
        error = Some( f64::abs(x2 - x1) );
        x0 = x1;
        x1 = x2;
    }

    if error > Some(tolerance) || x2 != x1 {
        None
    } else {
        Some((x2, i))
    }
}

fn main() {
    // F1
    let f1 = |x: f64| f64::exp(-x.powi(2)) - f64::cos(x);
    let mut res = secant(&f1, [1.0, 1.5], 10.0_f64.powi(-7), 20);

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
    res = secant(&f2, [0.0, 0.5], 10.0_f64.powi(-5), 20);

    if res == None {
        println!("Não foi possível convergir.\n");
    } else {
        println!("x: \t\t{}", res.unwrap().0);
        println!("f(x): \t\t{}", f64::abs( f2(res.unwrap().0) ));
        println!("Iterações: \t{}", res.unwrap().1);
        println!();
    }

    // F3
    let f3 = |x: f64| x.powi(3) - 9.0*x - 2.0;
    res = secant(&f3, [0.0, 0.5], 10.0_f64.powi(-10), 20);

    if res == None {
        println!("Não foi possível convergir.\n");
    } else {
        println!("x: \t\t{}", res.unwrap().0);
        println!("f(x): \t\t{}", f64::abs( f3(res.unwrap().0) ));
        println!("Iterações: \t{}", res.unwrap().1);
        println!();
    }
}
