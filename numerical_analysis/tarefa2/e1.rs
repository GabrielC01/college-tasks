// Resolução imperativa, só para o que foi pedido.
fn main() {
    let mut x4 = -1;
    let mut x3 = (1 - 5 * x4) / 3;
    let mut x2 = -(4 + x3 + 3 * x4);
    let mut x1 = -2 - 2*x2 - x3 - 2*x4;

    println!("x1, x2, x3, x4:\n{:?}", [x1, x2, x3, x4]);
}
