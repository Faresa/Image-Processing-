#############################################################################################


						///////MPHEPHU FARESA ->>>>> Department Of Computer Science
						Univaersity Of Cape Town <_____>  Unix & C++ Image Operations
								Assignment 4 | 2018 ~ April | CSC3022H 
												MPHFAR001
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~How To Use~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

To Run The Program , Change Directory to the bin/  , this is where the imageops object file is compiled to


The command line form is  
		-> imageops <option> OutputImageName

where  <option> represents the single operation to be performed and OutputImageName is the name for
the result image. 

	operations posiible are the following ;


	-a Image_name.pgm Other_image.pgm (add Image_name.pgm and Other_image.pgm)
	-s Image_name.pgm Other_image.pgm (subtract Other_image.pgm from Image_name.pgm)
	-i Image_name.pgm (invert Image_name.pgm)
	-l Image_name.pgm mask_name.pgm (mask Image_name.pgm with Other_image.pgm)
	-t Image_name.pgm f (threshold Image_name.pgm with integer value f)

eg.  ./imageops -a i1 i2 out.pgm 

NOTE :: Execute the program from the bin/ directory ;



~~~~~~~~~~~~~~~~~~UNIT TESTS & Their RESULTS~~~~~~~~~~~~~~~~~~~~


		on the root directory of the assignment , use the following bash command to execute the test cases 

								make-tests 
 
