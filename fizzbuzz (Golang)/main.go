package main

func main() {

	max := 100

	for i := 0; i < max; i++ {

		if i%3 == 0 || i%5 == 0 {

			if i%3 == 0 {
				print("fizz")
			}

			if i%5 == 0 {
				print("buzz")
			}

		} else {

			print(i)

		}

		print("\n")

	}

}
