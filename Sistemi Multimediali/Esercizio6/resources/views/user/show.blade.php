@extends('layouts.app')

@section('page_title', 'I Miei Hobby - Hobby')
@section('page_description', 'Qui viene mostrato un solo hobby')

@section('content')
    <div class="container">
        <div class="row justify-content-center">
            <div class="col-md-12">
                <div class="card">
                    <div class="card-header"><h1 class="m-0">{{$user -> name}}</h1></div>

                    <div class="card-body">
                        <div class="row">
                            <div class="col-md-9">
                                <div>
                                    <h2>Motto:</h2>
                                    <p>{{$user -> motto}}</p>
                                </div>
                                <div>
                                    <h2>Su di me:</h2>
                                    <p>{{$user -> about_me}}</p>
                                </div>

                                <div class="mt-3">
                                    @if($user->hobbies->count() > 0)
                                        <h2>Hobby di {{$user->name}}:</h2>
                                        <ul class="list-group">
                                            @foreach($user->hobbies as $hobby)
                                                <li class="list-group-item">
                                                    <a style="text-decoration: none" class="btn-link"
                                                       href="/hobby/{{$hobby->id}}">
                                                        @if(file_exists('img/hobbies/' . $hobby->id . '_thumb.jpg'))
                                                            <img src="/img/hobbies/{{$hobby->id}}_thumb.jpg"
                                                                 alt="thumb">
                                                        @endif
                                                        <span class="ml-2">{{$hobby -> name}}</span>
                                                    </a>
                                                    <span class="mr-2 text-center float-right">
                                                        Creato {{$hobby->created_at->diffForHumans()}}
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
                                    @else
                                        <h2>{{$user->name}} non ha inserito nessun hobby</h2>
                                    @endif
                                </div>
                            </div>
                            @if(file_exists('img/users/' . $user->id . '_large.jpg') ||
                                file_exists('img/users/' . $user->id . '_pixelated.jpg'))
                                <div class="col-md-3">
                                    @if(auth()->user() && file_exists('img/users/' . $user->id . '_large.jpg'))
                                        <img class="img-thumbnail" src="/img/users/{{$user->id}}_large.jpg"
                                             alt="{{ $user->name }}">
                                    @endif

                                    @if(!auth()->user() && file_exists('img/users/' . $user->id . '_pixelated.jpg'))
                                        <img class="img-thumbnail" src="/img/users/{{$user->id}}_pixelated.jpg"
                                             alt="{{ $user->name }}">
                                    @endif
                                </div>
                            @endif
                        </div>
                    </div>

                </div>
                <div class="mt-3">
                    <a class="btn btn-link btn-sm" href="{{\Illuminate\Support\Facades\URL::previous()}}">
                        <i class="fas fa-arrow-circle-up"></i> Ritorna Indietro
                    </a>
                </div>
            </div>
        </div>
@endsection
