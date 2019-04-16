# find max count of threads in critical section
{
  if ($1 == "in") x++ 
  if ($1 == "out") x-- 
  if (x > max) max = x
}
END {
  print "max in CS = "max
}
