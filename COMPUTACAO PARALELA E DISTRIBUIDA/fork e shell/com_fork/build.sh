#GitHub Autor: AugustoSavi
mkdir ./build
for filename in *; do
    if echo "$filename" | grep -q ".c"
	then
		echo "$filename"
		gcc $filename -o "build/${filename%.*}"
	fi
done
./build/cpdexer61_fork