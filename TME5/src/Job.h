#pragma once

namespace pr {

    class Job {
    public:
        virtual void run () = 0;
        virtual ~Job() {};
    };


    class PixelJob : public Job {
        color calcul(const Scene scene, int x, int y){
            auto & screenPoint = screen[y][x];
            // le rayon a inspecter
            Rayon  ray(scene.getCameraPos(), screenPoint);

            int targetSphere = findClosestInter(scene, ray);

            if (targetSphere == -1) {
                // keep background color
                continue ;
            } else {
                const Sphere & obj = *(scene.begin() + targetSphere);
                // pixel prend la couleur de l'objet
                Color finalcolor = computeColor(obj, ray, scene.getCameraPos(), lights);
                // le point de l'image (pixel) dont on vient de calculer la couleur
                Color & pixel = pixels[y*scene.getHeight() + x];
                // mettre a jour la couleur du pixel dans l'image finale.
                pixel = finalcolor;
            }
        }
        const Scene scene;
        int x;
        int y;
        color* ret;
        std::vector<Vec3D> lights;
    public:
        PixelJob(const Scene scene, int x, int y, color ret){}
        void run () {
            * ret = calcul(const Scene scene, int x, int y);
        }
        ~PixelJob(){}
    };
// Job concret : exemple

/**
class SleepJob : public Job {
	int calcul (int v) {
		std::cout << "Computing for arg =" << v << std::endl;
		// traiter un gros calcul
		this_thread::sleep_for(1s);
		int ret = v % 255;
		std::cout << "Obtained for arg =" << arg <<  " result " << ret << std::endl;
		return ret;
	}
	int arg;
	int * ret;
public :
	SleepJob(int arg, int * ret) : arg(arg), ret(ret) {}
	void run () {
		* ret = calcul(arg);
	}
	~SleepJob(){}
};
**/

}
