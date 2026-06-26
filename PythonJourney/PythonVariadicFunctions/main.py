
def vaiadicFunc(index: int, name: str, **keyword_args ):
	print (index)
	print (name)
	print (keyword_args)
	print (keyword_args['family'])
	print (keyword_args['age'])



def main():
	vaiadicFunc(10, "Alex", family="Ford", age=35)


if __name__ == "__main__":
	main()