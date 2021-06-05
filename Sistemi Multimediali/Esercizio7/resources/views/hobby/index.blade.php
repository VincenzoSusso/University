@extends('layouts.app')

@section('page_title', 'I Miei Hobby - Hobby')

@isset($filter)
    @section('page_description', 'Tutti gli hobby filtrati con il tag ' . $filter -> name . ' sono visualizzati qui')
@else
    @section('page_description', 'Tutti gli hobby sono visualizzati qui')
@endisset

@section('content')
    <div class="container">
        <div class="row justify-content-center">
            <div class="col-md-12">
                <div class="card">
                    <div class="card-header">
                        @isset($filter)
                            <div>
                                <h1 class="m-0 d-inline">Hobby filtrati con il tag: </h1>
                                <span style="background-color: {{'#' . $filter->color}}"
                                      class="p-2 text-white font-weight-bold rounded align-text-bottom">{{$filter -> name}}
                                </span>
                                <a class="float-right d-inline mt-2" href="/hobby">Mostra tutti gli Hobby</a>
                            </div>
                        @else
                            <h1 class="m-0">Hobby</h1>
                        @endisset
                    </div>

                    <div class="card-body">
                        <ul class="list-group">
                            @foreach($hobbies as $hobby)
                                <li class="list-group-item">
                                    <a title="Mostra l'hobby" style="text-decoration: none" class="btn-link"
                                       href="/hobby/{{$hobby->id}}">
                                        @if(file_exists('img/hobbies/' . $hobby->id . '_thumb.jpg'))
                                            <img src="/img/hobbies/{{$hobby->id}}_thumb.jpg" alt="thumb">
                                        @endif
                                        <span class="ml-2">{{$hobby -> name}}</span>
                                    </a>
                                    @auth
                                        @can('update', $hobby)
                                            <a class="btn btn-sm btn-light border-dark ml-2"
                                               href="/hobby/{{$hobby->id}}/edit"><i
                                                    class="fas fa-edit"></i> Modifica</a>
                                        @endcan

                                        @can('delete', $hobby)
                                            <form class="ml-2" style="display: inline"
                                                  action="hobby/{{$hobby->id}}"
                                                  method="post">
                                                @csrf
                                                @method('DELETE')
                                                <input class="btn btn-sm btn-outline-danger" type="submit"
                                                       value="Elimina"/>
                                            </form>
                                        @endcan
                                    @endauth
                                    <span
                                        class="mr-2 text-center float-right">Creato da:
                                        <a style="text-decoration: none" href="/user/{{$hobby->user->id}}">
                                            @if(file_exists('img/users/' . $hobby->user->id . '_thumb.jpg'))
                                                <img class="rounded" src="/img/users/{{$hobby->user->id}}_thumb.jpg"
                                                     alt="thumb">
                                            @endif
                                            {{$hobby->user->name}}
                                        </a>
                                        ({{$hobby->user->hobbies->count()}} creati), {{$hobby->created_at->diffForHumans()}}
                                    </span>
                                    <br/>
                                    <div class="my-3">
                                        @foreach($hobby->tags as $tag)
                                            <a style="text-decoration: none" class="float-left ml-1"
                                               href="/hobby/tag/{{$tag->id}}">
                                                <span style="background-color: {{'#' . $tag->color}}"
                                                      class="p-2 text-white font-weight-bold rounded">{{$tag -> name}}
                                                </span>
                                            </a>
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
            </div>
        </div>
@endsection
