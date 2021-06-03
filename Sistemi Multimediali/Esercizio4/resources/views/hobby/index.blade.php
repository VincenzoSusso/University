@extends('layouts.app')

@section('page_title', 'I Miei Hobby - Hobby')
@section('page_description', 'Tutti gli hobby sono visualizzati qui')

@section('content')
    <div class="container">
        <div class="row justify-content-center">
            <div class="col-md-12">
                <div class="card">
                    <div class="card-header">Hobby</div>

                    <div class="card-body">
                        <ul class="list-group">
                            @foreach($hobbies as $hobby)
                                <li class="list-group-item"><a class="btn-link"
                                                               href="hobby/{{$hobby->id}}">{{$hobby -> name}}</a>
                                    @auth
                                        <a class="btn btn-sm btn-light ml-2" href="hobby/{{$hobby->id}}/edit"><i
                                                class="fas fa-edit"></i> Modifica</a>
                                    @endauth
                                    <span
                                        class="ml-4 text-center">Creato da: <a
                                            href="user/{{$hobby->user->id}}">{{$hobby->user->name}}</a> ({{$hobby->user->hobbies->count()}} creati), {{$hobby->created_at->diffForHumans()}}
                                    </span>
                                    @auth
                                        <form class="float-right" style="display: inline" action="hobby/{{$hobby->id}}"
                                              method="post">
                                            @csrf
                                            @method('DELETE')
                                            <input class="btn btn-sm btn-outline-danger" type="submit" value="Elimina"/>
                                        </form>
                                    @endauth
                                    <br/>
                                    <div class="my-3">
                                        @foreach($hobby->tags as $tag)
                                            <span style="background-color: {{'#' . $tag->color}}"
                                                  class="p-2 text-white font-weight-bold rounded">{{$tag -> name}}</span>
                                        @endforeach
                                    </div>
                                </li>
                            @endforeach
                        </ul>
                    </div>
                </div>
                <div class="mt-3">
                    {{ $hobbies->links() }}
                </div>
                @auth
                    <div class="mt-3">
                        <a class="btn btn-success btn-sm" href="hobby/create">
                            <i class="fas fa-plus-circle"></i> Crea un nuovo Hobby
                        </a>
                    </div>
                @endauth
            </div>
        </div>
@endsection
