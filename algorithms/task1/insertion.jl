# Ordenação por inserção.
function sort_insertion(a::Vector{UInt16})
	for j = 2:length(a)
		key = a[j]
		i = j - 1
		while i > 0 && a[i] > key
			a[i+1] = a[i]
			i = i - 1
		end
		a[i+1] = key
	end
end


# Ordenação por intercalação.
function sort_merge(a::Vector{UInt16})
    if length(a) == 1 
        return a
    end

    mid = trunc(UInt16, length(a) / 2)
    l1 = sort_merge(a[1:mid])
    l2 = sort_merge(a[mid+1:length(a)])

    return merge(l1, l2)
end

function merge(a::Vector{UInt16}, b::Vector{UInt16})
    c = rand(UInt16, 0)

    while length(a) > 0 && length(b) > 0
        if a[1] > b[1]
            push!(c, b[1])
            popat!(b, 1)
        else
            push!(c, a[1])
            popat!(a, 1)
        end
    end

    while length(a) > 0
        push!(c, a[1])
        popat!(a, 1)
    end

    while length(b) > 0
        push!(c, b[1])
        popat!(b, 1)
    end

    return c
end


# Procedimento para imprimir conteúdo de vetor.
function print_vector(a::Vector{UInt16})
    for i in 1:length(a)
        print(a[i])
        print(" ")
    end
end


function main()
	# Preparar dados de entrada.
	A = rand(UInt16, 100)
	B = rand(UInt16, 1000)
	C = rand(UInt16, 10000)
	D = rand(UInt16, 100000)

	# Ordenação por inserção.
    @time sort_insertion(copy(A))
	@time sort_insertion(copy(B))
	@time sort_insertion(copy(C))
	@time sort_insertion(copy(D))
	
    println()

	# Ordenação por intercalação.
    @time sort_merge(copy(A))
	@time sort_merge(copy(B))
	@time sort_merge(copy(C))
	@time sort_merge(copy(D))
end

main()
