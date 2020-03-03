function wa_run(n) {
    const element = document.getElementById('result');

    const start = new Date();
    const result = _wa_find_nth_prime(n);
    const time = new Date() - start;
    element.innerHTML = "The "+ n.toString() +"th prime number is "+ result.toString()
        +".<br><br>It took " + time.toString() + "ms to run by WebAssembly";
}

function js_run(n) {
    const element = document.getElementById('result');

    const start = new Date();
    const result = js_find_nth_prime(n);
    const time = new Date() - start;
    element.innerHTML = "The "+ n.toString() +"th prime number is "+ result.toString()
        +".<br><br>It took " + time.toString() + "ms to run by Javascript";
}

function js_find_nth_prime(n) {
    let prime_found = 0;
    let current = 2;
    let prime = 0;
    while(prime_found < n) {
        if (js_is_prime(current)) {
            prime_found++;
            prime = current;
        }
        current++;
    }
    return prime;
}

function js_is_prime(n) {
    for(let i=2; i<n-1; i++)
        if(n%i === 0)
            return false;
    return true;
}