task :default => 'build:test'

namespace :build do
  task :release do
    system("g++ -fPIC -fno-common -c Twazlr/*.cpp -I. -I/usr/include")
    system("g++ -dynamiclib -W1 -O3 -o Build/libtwazlr.dylib *.o -ltokyocabinet -lpthread")
  end
  
  task :debug do
    system("g++ -FPIC -fno-common -c Twazlr/*.cpp -I. -I/usr/include")
    system("g++ -dynamiclib -o Build/libtwazlr.dylib *.o -ltokyocabinet -lpthread")
  end
  
  task :test => :debug do
    system('g++ -o Build/Test Test/*.cpp -L./Build -I. -ltokyocabinet -ltwazlr -lgtest -lgmock')
    system('./Build/Test')
  end
end