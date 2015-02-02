// Title:       Euler Project Problem 2
// Description: Find the sum of even fib numbers whose values don't exceed 4 mill

// Note: No reason to use the big lib for this, but it's good learnings.

package main

import (
    "fmt"
    "math/big"
)


func fib(cutoff *big.Int) *big.Int {
    a := big.NewInt(0)
    b := big.NewInt(1)
    c := big.NewInt(0)
    total := big.NewInt(0)
    mod := new(big.Int)

    for {
       c.Add(a,b)
       a.Set(b)
       b.Set(c)

       if b.Cmp(cutoff) == 1 {
            break;
       }

       mod.Mod(b, big.NewInt(2))

       if mod.Cmp(big.NewInt(0)) == 0 {
           total.Add(total, b)
       }

    }

    return total
}

func main() {
    fmt.Println("Sum ", fib(big.NewInt(4000000)))
}

