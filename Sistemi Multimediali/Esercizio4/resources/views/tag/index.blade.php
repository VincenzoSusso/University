@extends('layouts.app')

@section('page_title', 'I Miei Hobby - Tag')
@section('page_description', 'Tutti gli tag sono visualizzati qui')

@section('content')
    <div class="container">
        <div class="row justify-content-center">
            <div class="col-md-12">
                <div class="card">
                    <div class="card-header">Tag</div>

                    <div class="card-body">
                        <ul class="list-group">
                            @foreach($tags as $tag)
                                <li class="list-group-item">
                                    <span style="background-color: {{'#' . $tag->color}}"
                                          class="p-2 text-white font-weight-bold rounded">{{$tag -> name}}</span>
                                    <a class="btn btn-sm btn-light ml-4" href="tag/{{$tag->id}}/edit"><i
                                            class="fas fa-edit"></i> Modifica</a>
                                    <form class="float-right" style="display: inline" action="tag/{{$tag->id}}"
                                          method="post">
                                        @csrf
                                        @method('DELETE')
                                        <input class="btn btn-sm btn-outline-danger" type="submit" value="Elimina"/>
                                    </form>
                                </li>
                            @endforeach
                        </ul>
                    </div>
                </div>
                <div class="mt-3">
                    <a class="btn btn-success btn-sm" href="tag/create">
                        <i class="fas fa-plus-circle"></i> Crea un nuovo Tag
                    </a>
                </div>
            </div>
        </div>
@endsection
