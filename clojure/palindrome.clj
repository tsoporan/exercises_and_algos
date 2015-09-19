; Test if string is palindrome

(defn isPalindrome? [s]
  (if (= s (apply str (reverse s)))
    true
    false
  )
)

; Some sanity testing
(println (isPalindrome? "abc"))
(println (isPalindrome? "TTT"))
(println (isPalindrome? "121"))
(println (isPalindrome? "abccba"))
(println (isPalindrome? "ABCcba"))
