#ifndef CAMERA_H
#define CAMERA_H

#include "vec3.h"
#include "matrix.h"

class camera
{
public: 

    camera(const vec3& from, const vec3& at, float vert_fov, float asp_ratio):
        look_from(from), look_at(at), vfov(vert_fov), aspect_ratio(asp_ratio)
    {
       // Camera's local axes 
       forward = unit_vector(look_from - look_at);  // +z 
       right = unit_vector(cross(up, forward));     // +x
       up = cross(forward, right);                  // +y
    }

    // Returns the view matrix
    mat4 get_view()
    {
        mat4 view; 
        // view matrix values, assuming column vector notation
        std::vector<float> v_view = {
            right.x(), up.x(), forward.x(), look_from.x(),
            right.y(), up.y(), forward.y(), look_from.y(),
            right.z(), up.z(), forward.z(), look_from.z(),
                    0,      0,           0,             1 
        };

        view = v_view;
        return view;
    }
        
    mat4 get_perspective()
    {

    }

    vec3 look_from;
    vec3 look_at; 
    vec3 right, up, forward;
    float vfov, aspect_ratio;
    float near, far;
};

#endif // CAMERA_H
