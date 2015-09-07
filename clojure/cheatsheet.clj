;; Clojure reminders

; Prefix notatation
(+ 2 3)

(* (- 2 3) (+ 3 4))

; Organization, s-expressions, sexps.
(*
  (+ (* 2 5)
     (- 5 3))

  (- (- 10 5 ))
)

; Vars
(def a 5)

(+ a a)
(+ (* a 2) (* a a))

; Functions
(defn square [x] ( * x x ))

(square 5) ;25

; Multiple args
(defn prod [x y] (* x y))

(prod 5 4) ;20

; Variadic args
(defn prodmaxmin [& nums] (* (apply max nums) (apply min nums)))
(prodmaxmin [1 2 3]) ; 3*1 -> 3

; Different arities for the same function
(defn arities
  ([x] x)
  ([x y] (+ x y))
  ([x y z] (* x y z))
)

(arities 3) ;3
(arities 3 4) ;7
(arities 1 2 3) ;6

; Multiple funcs
(defn foo [x]
  (+ x (bar x 3))
)

(defn bar [x y] (* x y ))

(foo 3) ; 12

