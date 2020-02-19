//1
const inverter = (n, t) => (n == 0) ? t : inverter(Math.round(n / 10), (t * 10) + n % 10)


//2


//          5, 5 , 10

const imprimaAteZero = (n, max, i = max * 3) => {
    setTimeout(() => {
        console.log(n)
        if (max >= i + max) {
            imprimaAteZero(n + 1, 0, i - 1)
        } else if (max == i - max) {
            return;
        } else {
            imprimaAteZero(n - 1, max, i - 1)
        }
    }, 2000);

}

imprimaAteZero(5, 5)