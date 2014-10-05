#Check if given number is a prime, using the trial/error method.

def primeTest(num)

    # Naive method check n, from 2 to n - 1
    # i.e prime test for 5 is check divisibility up from 2 ending at 4

    start = 2

    if num <= 3
        return true
    end

    while start <= (num - 1) do
        if num % start == 0
            return false
        end
        start += 1 
    end

    return true

end

puts(primeTest(3) == true)
puts(primeTest(5) == true)
puts(primeTest(10) == false)
puts(primeTest(1000) == false)
puts(primeTest(1009) == true)
