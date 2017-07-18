#glslangValidator -V triangle.vert
#glslangValidator -V triangle.frag

source /home/philipp/Programme/VulkanSDK/1.0.54.0/setup-env.sh

for f in *; do
    if [[ -d $f ]]; then
        cd $f
        if [[ ! -d out ]]; then
            mkdir out
        fi
        cd out
        for s in ../*; do
            if [[ -f $s ]]; then
                echo "$s"
                glslangValidator -V "$s"
            fi
        done
        cd ..
        cd ..
    fi
done