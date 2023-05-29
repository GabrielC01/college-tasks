/* Função da bissecção. */
/* Parâmetros: função nos reais qualquer, limite inferior do intervalo, limite superior do
 * intervalo, e a tolerância.
 * Retorno: Ou uma tupla com o valor convergido e o número de iterações, ou nulo (None). */
fn bisection(f: &dyn Fn(f64) -> f64, lbound: f64, ubound: f64, error: f64) -> Option<(f64, i32)> {
    let mut a = lbound;
    let mut b = ubound;
    let mut xk: f64 = 0.0;
    let mut num_iterations = 0;

    while f64::abs(b - a) > error {
        xk = (a + b) / 2.0;
        if f(a)*f(xk) > 0.0 {
            a = xk;
        } else {
            b = xk;
        }
        num_iterations += 1;
    }

    Some((xk, num_iterations))
}

fn main() {
    // F1
    let f1 = |x: f64| std::f64::consts::E.powf(-x.powi(2)) - x.cos();
    let mut root = bisection(&f1, 1.0, 1.5, 10.0_f64.powi(-7)).unwrap();
    println!("Convergência (x): {:.8};\nnúmero de iterações: {}", root.0, root.1);
    println!("f(x) = {:.8}", f64::abs(f1(root.0)));

    println!();

    // F2
    let f2 = |x: f64| x.powi(3) - x - 1.0;
    root = bisection(&f2, 1.0, 1.5, 10.0_f64.powi(-5)).unwrap();
    println!("Convergência (x): {:.8};\nnúmero de iterações: {}", root.0, root.1);
    println!("f(x) = {:.8}", f64::abs(f2(root.0)));

    println!();

    // F3
    let f3 = |x: f64| x.powi(3) - 9.0*x + 2.0;
    root = bisection(&f3, 0.0, 1.0, 10.0_f64.powi(-10)).unwrap();
    println!("Convergência (x): {:.8};\nnúmero de iterações: {}", root.0, root.1);
    println!("f(x) = {:.8}", f64::abs(f3(root.0)));
}
