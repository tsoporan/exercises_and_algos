; Given a string sum up all the numbers (individual) within 
; Ex:
;   abc123def
;   1 + 2 + 3 = 6
; Test string:
;   96h11k4959q615948s50922o38h1453ij38w73413d5577lzrqw3780b389750vf100zd29z73j5wh73l6965n85vm77cw10awrjr29265289222238n10013uk10062f9449acbhfgcm35j78q80

(require '[clojure.string :as s])

(def test-string "96h11k4959q615948s50922o38h1453ij38w73413d5577lzrqw3780b389750vf100zd29z73j5wh73l6965n85vm77cw10awrjr29265289222238n10013uk10062f9449acbhfgcm35j78q80")

(defn sum-string [text]
  (reduce + (map #(Integer/parseInt %) (s/split (s/join "" (remove s/blank? (s/split test-string  #"[A-Za-z]+") )) #"" )))
)

(println (= (sum-string test-string) 446))



