//
// Created by yongli on 21/10/2022.
//

#ifndef TP5_JOP_HPP
#define TP5_JOP_HPP

namespace pr {

    class Job {
    public:
        virtual void run () = 0;
        virtual ~Job() {};
    };
    class SleepJob : public Job {
        int calcul (int v) {
            std::cout << "Computing for arg =" << v << std::endl;
            // traiter un gros calcul
            this_thread::sleep_for(1s);
            int ret = v % 255;
            std::cout << "Obtained for arg =" << arg << " result " << ret << std::endl;
            return ret;
        }
        int arg;
        int * ret;
    public :
        SleepJob(int arg, int * ret) : arg(arg), ret(ret) {}
        void run () {
            // TODO : compléter
        }
        ~SleepJob(){}
    };
}

#endif //TP5_JOP_HPP
