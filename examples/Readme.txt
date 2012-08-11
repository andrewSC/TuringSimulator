So each of these ExampleConfig files contains the defintion for some TM. 
If you want to test a particular defintion all you gotta do is copy the 
header and cpp file from this directory to the directory above it with
all the other files and rename it ExampleConfig.* where * represents the
.h extension or the .cpp extension.

The defintions are as follows:
ExampleConfig1.cpp & ExampleConfig1.h: (0 union 1)* 0 (0 union 1)*
ExampleConfig2.cpp & ExampleConfig2.h: { w#w | w in {0,1}* }
ExampleConfig3.cpp & ExampleConfig3.h: { w | w in {0,1}*, w contains twice as many 1s as 0s }
