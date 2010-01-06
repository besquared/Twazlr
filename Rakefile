task :default => 'build:test:all'

namespace :build do
  task :release do
    system("g++ -fPIC -fno-common -c Source/*.cpp -I/usr/include")
    system("g++ -dynamiclib -W1 -O3 -o Build/libtwazlr.dylib *.o -ltokyocabinet -lpthread")
  end
  
  task :debug do
    system("g++ -c Source/*.cpp -I/usr/include")
    system("g++ -dynamiclib -o Build/libtwazlr.dylib *.o -ltokyocabinet -lpthread")
  end
  
  task :test do
    system('g++ -o Test/Build/test-all Test/*.cpp -L./Build -I. -ltokyocabinet -ltwazlr -lgtest')
  end
end