// Title       : Euler Project Problem 
// Description : Find the sum of all the multiples of 3 or 5 below 1000.

package main

import "fmt"

func main() {

    nums := []int{}
    sum := 0

    for i:= 0; i < 1000; i++ {
        if i % 3 == 0 || i % 5 == 0 || i % 6 == 0 || i % 9 == 0 {
            nums = append(nums, i)
        }
    }

    for _, el := range nums {
        sum += el
    }

    fmt.Println("Sum", sum)
}
