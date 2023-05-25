<body>
<img src="https://npr.brightspotcdn.com/dims4/default/aacc2fe/2147483647/strip/true/crop/870x536+67+0/resize/880x542!/quality/90/?url=http%3A%2F%2Fnpr-brightspot.s3.amazonaws.com%2Flegacy%2Fsites%2Fradiowest%2Ffiles%2F201507%2Fmonty_python3.jpg">

<br>
<h1>The Monty language</h1>

<h3>Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files.</h3>
<br>
<h2>General</h2>

    What do LIFO and FIFO mean
    What is a stack, and when to use it
    What is a queue, and when to use it
    What are the common implementations of stacks and queues
    What are the most common use cases of stacks and queues
    What is the proper way to use global variables
<br>
<h2>Compilation & Output</h2>

    Your code will be compiled this way:

    $ gcc -Wall -Werror -Wextra -pedantic *.c -o monty
<br>
<h2>Our tasks and the functions we have include:</h2>
<ul>
<li>push, pall</li>
<li>pint</li>
<li>pop</li>
<li>swap</li>
<li>add</li>
<li>nop</li>
</ul>
<h3>With this proyect we will be working on the Monty languge, working with functions such as pop, pall, pint, push, etc. In general workign with stacks and how they work.</h3>
<br>
<h2>Example</h2>

    $ cat bytecodes/12.m
    push 1
    push 2
    push 3
    pall
    add
    pall
    $ ./monty bytecodes/12.m
    3
    2
    1
    5
    1
<br>
<h2>Challenges</h2>
<ul>
<li>Develop an algorithm to deal with spaces inside the files</li>
<li>Be able to execute commands without ending the program</li>
<li>Deal with "malloc" and "free" to manage memory</li>    
</ul>
<h2>Authors</h2>
<ul>
<li>Norman Torres (ntpadovani)</li>
    Full-Stack Software Student at Holberton School of Code Puerto Rico trying to make a difference in the technology world.
<li><a href="https://www.linkedin.com/in/norman-t-p-88979553/" target="_blank">
<img src=https://img.shields.io/badge/linkedin-%231E77B5.svg?&style=for-the-badge&logo=linkedin&logoColor=white alt=linkedin style="margin-bottom: 5px;" />
</a></li>
<li>Ivanzka Rodriguez (Ivanzkaa)</li>
</ul>
</body>
